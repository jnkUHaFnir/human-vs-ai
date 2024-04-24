    #!/usr/bin/perl
    # pebsfix/pebsfixup -- fix assembler source for PEBS usage
    #
    # command line options:
    #   "-l" -- do _not_ use lea
    #   "-D[diff-file]" -- show differences (default output: "./DIFF")
    #   "-n10" -- do _not_ use register %r10 for temporary (default is use it)
    #   "-o" -- overwrite input files (can be multiple)
    #   "-O<outfile>" -- output file (only one .s input allowed)
    #   "-q" -- suppress warnings
    #   "-T[lvl]" -- debug trace
    #
    # "-o" and "-O" are mutually exclusive
    #
    # command line script test options:
    #   "-N[TPA]" -- disable temp register types [for testing]
    #   "-P" -- force push/pop on all functions
    #
    # command line arguments:
    #   1-- list of .s files to process [or directory to search]
    #       for a given file "foo.s", output is to "foo.TMP"
    #       if (-o is given, "foo.TMP" is renamed to "foo.s")
    #
    # suggested usage:
    #   change build to produce .s files
    #   FROM:
    #     cc [options] -c foo.c
    #   TO:
    #     cc [options] -c -S foo.c
    #     pebsfixup -o foo.s
    #     cc -c foo.s
    #
    # suggested compiler options:
    # [probably only really needed if push/pop required. use -NP to verify]
    #   (1) use either of
    #       -O2 -fno-optimize-sibling-calls
    #       -O1
    #   (2) use -mno-omit-leaf-frame-pointer
    #   (3) use -mno-red-zone [probably not required in any case]
    #
    # NOTES:
    #   (1) red zones are only really useful for leaf functions (i.e. if fncA calls
    #       fncB, fncA's red zone would be clobbered)
    #   (2) pushing onto the stack isn't a problem if there is a formal stack frame
    #   (3) the push is okay if the function has no more than six arguments (i.e.
    #       does _not_ use positive offsets from %rsp to access them)
    #pragma pgmlns
    use strict qw(vars subs);
    our $pgmtail;
    our $opt_T;
    our $opt_D;
    our $opt_l;
    our $opt_n10;
    our $opt_N;
    our $opt_P;
    our $opt_q;
    our $opt_o;
    our $opt_O;
    our $opt_s;
    our @reguse;
    our %reguse_tobase;
    our %reguse_isbase;
    our $regusergx;
    our @regtmplist;
    our %regtmp_type;
    our $diff;
    our $sepflg;
    our $fatal;
    our @cmtprt;
    master(@ARGV);
    exit(0);
    # master -- master control
    sub master
    {
        my(@argv) = @_;
        my($xfsrc);
        my($file,@files);
        my($bf);
        $pgmtail = "pebsfixup";
        optget(\@argv);
        # define all known/usable registers
        regusejoin();
        # define all registers that we may use as a temporary
        regtmpall();
        if (defined($opt_D)) {
            unlink($opt_D);
        }
        # show usage
        if (@argv <= 0) {
            $file = $0;
            open($xfsrc,"<$file") ||
                sysfault("$pgmtail: unable to open '%s' -- $!\n",$file);
            while ($bf = <$xfsrc>) {
                chomp($bf);
                next if ($bf =~ /^#!/);
                last unless ($bf =~ s/^#//);
                $bf =~ s/^# ?//;
                print($bf,"\n");
            }
            close($xfsrc);
            exit(1);
        }
        foreach $file (@argv) {
            if (-d $file) {
                dodir(\@files,$file);
            }
            else {
                push(@files,$file);
            }
        }
        if (defined($opt_O)) {
            sysfault("$pgmtail: -O may have only one input file\n")
                if (@files != 1);
            sysfault("$pgmtail: -O and -o are mutually exclusive\n")
                if ($opt_o);
        }
        foreach $file (@files) {
            dofile($file);
        }
        if (defined($opt_D)) {
            exec("less",$opt_D);
        }
    }
    # dodir -- process directory
    sub dodir
    {
        my($files,$dir) = @_;
        my($file,@files);
        @files = (`find $dir -type f -name '*.s'`);
        foreach $file (@files) {
            chomp($file);
            push(@$files,$file);
        }
    }
    # dofile -- process file
    sub dofile
    {
        my($file) = @_;
        my($ofile);
        my($xfsrc);
        my($xfdst);
        my($bf,$lno,$outoff);
        my($fixoff);
        my($lhs,$rhs);
        my($xop,$arg);
        my($ix);
        my($sym,$val,$typ);
        my(%sym_type);
        my($fnc,$fnx,%fnx_lookup,@fnxlist);
        my($retlist);
        my($uselook,@uselist,%avail);
        my($fixreg,$fixrtyp);
        my($sixlist);
        my($fix,$fixlist);
        my($fixtot);
        my(@fix);
        my(@outlist);
        my($relaxflg);
        my($cmtchr);
        undef($fatal);
        undef(@cmtprt);
        msgprt("\n")
            if ($sepflg);
        $sepflg = 1;
        msgprt("$pgmtail: processing %s ...\n",$file);
        $cmtchr = "#";
        cmtprt("%s\n","-" x 78);
        cmtprt("FILE: %s\n",$file);
        # get the output file
        $ofile = $file;
        sysfault("$pgmtail: bad suffix -- file='%s'\n",$file)
            unless ($ofile =~ s/[.]s$//);
        $ofile .= ".TMP";
        # use explicit output file
        if (defined($opt_O)) {
            $ofile = $opt_O;
            sysfault("$pgmtail: output file may not be input file -- use -o instead\n")
                if ($ofile eq $file);
        }
        open($xfsrc,"<$file") ||
            sysfault("$pgmtail: unable to open '%s' -- $!\n",$file);
        $lno = 0;
        while ($bf = <$xfsrc>) {
            chomp($bf);
            $bf =~ s/\s+$//;
            $outoff = $lno;
            ++$lno;
            push(@outlist,$bf);
            # clang adds comments
            $ix = index($bf,"#");
            if ($ix >= 0) {
                $bf = substr($bf,0,$ix);
                $bf =~ s/\s+$//;
            }
            # look for ".type blah, @function"
            # NOTE: this always comes before the actual label line [we hope ;-)]
            if ($bf =~ /^\s+[.]type\s+([^,]+),\s*(\S+)/) {
                ($sym,$val) = ($1,$2);
                $val =~ s/^\@//;
                $sym_type{$sym} = $val;
                cmtprt("\n");
                cmtprt("TYPE: %s --> %s\n",$sym,$val);
                next;
            }
            # look for "label:"
            if ($bf =~ /^([a-z_A-Z][a-z_A-Z0-9]*):$/) {
                $sym = $1;
                next if ($sym_type{$sym} ne "function");
                $fnc = $sym;
                cmtprt("FUNCTION: %s\n",$fnc);
                $fnx = {};
                $fnx_lookup{$sym} = $fnx;
                push(@fnxlist,$fnx);
                $fnx->{fnx_fnc} = $fnc;
                $fnx->{fnx_outoff} = $outoff;
                $uselook = {};
                $fnx->{fnx_used} = $uselook;
                $retlist = [];
                $fnx->{fnx_retlist} = $retlist;
                $fixlist = [];
                $fnx->{fnx_fixlist} = $fixlist;
                $sixlist = [];
                $fnx->{fnx_sixlist} = $sixlist;
                next;
            }
            # remember all registers used by function:
            while ($bf =~ /($regusergx)/gpo) {
                $sym = ${^MATCH};
                $val = $reguse_tobase{$sym};
                dbgprt(3,"dofile: REGUSE sym='%s' val='%s'\n",$sym,$val);
                $uselook->{$sym} += 1;
                $uselook->{$val} += 1
                    if ($val ne $sym);
            }
            # handle returns
            if ($bf =~ /^\s+ret/) {
                push(@$retlist,$outoff);
                next;
            }
            if ($bf =~ /^\s+rep[a-z]*\s+ret/) {
                push(@$retlist,$outoff);
                next;
            }
            # split up "movq 16(%rax),%rax" ...
            $ix = rindex($bf,",");
            next if ($ix < 0);
            # ... into "movq 16(%rax)"
            $lhs = substr($bf,0,$ix);
            $lhs =~ s/\s+$//;
            # check for "movq 16(%rsp)" -- this means that the function has/uses
            # more than six arguments (i.e. we may _not_ push/pop because it
            # wreaks havoc with positive offsets)
            # FIXME/CAE -- we'd have to adjust them by 8 which we don't do
            (undef,$rhs) = split(" ",$lhs);
            if ($rhs =~ /^(\d+)[(]%rsp[)]$/) {
                push(@$sixlist,$outoff);
                cmtprt("SIXARG: %s (line %d)\n",$rhs,$lno);
            }
            # ... and "%rax"
            $rhs = substr($bf,$ix + 1);
            $rhs =~ s/^\s+//;
            # target must be a [simple] register [or source scan will blow up]
            # (e.g. we actually had "cmp %ebp,(%rax,%r14)")
            next if ($rhs =~ /[)]/);
            # ensure we have the "%" prefix
            next unless ($rhs =~ /^%/);
            # we only want the full 64 bit reg as target
            # (e.g. "mov (%rbx),%al" doesn't count)
            $val = $reguse_tobase{$rhs};
            next if ($val ne $rhs);
            # source operand must contain target register
            next unless ($lhs =~ /$rhs/);
            ###cmtprt("1: %s,%s\n",$lhs,$rhs);
            # source operand must be of the "right" type
            # FIXME/CAE -- we may need to revise this
            next unless ($lhs =~ /[(]/);
            cmtprt("NEEDFIX: %s,%s (line %d)\n",$lhs,$rhs,$lno);
            # remember the place we need to fix for later
            $fix = {};
            push(@$fixlist,$fix);
            $fix->{fix_outoff} = $outoff;
            $fix->{fix_lhs} = $lhs;
            $fix->{fix_rhs} = $rhs;
        }
        close($xfsrc);
        # get total number of fixups
        foreach $fnx (@fnxlist) {
            $fixlist = $fnx->{fnx_fixlist};
            $fixtot += @$fixlist;
        }
        msgprt("$pgmtail: needs %d fixups\n",$fixtot)
            if ($fixtot > 0);
        # fix each function
        foreach $fnx (@fnxlist) {
            cmtprt("\n");
            cmtprt("FNC: %s\n",$fnx->{fnx_fnc});
            $fixlist = $fnx->{fnx_fixlist};
            # get the fixup register
            ($fixreg,$fixrtyp) = regtmploc($fnx,$fixlist);
            # show number of return points
            {
                $retlist = $fnx->{fnx_retlist};
                cmtprt("  RET: %d\n",scalar(@$retlist));
                last if (@$retlist >= 1);
                # NOTE: we display this warning because we may not be able to
                # handle all situations
                $relaxflg = (@$fixlist <= 0) || ($fixrtyp ne "P");
                last if ($relaxflg && $opt_q);
                errprt("$pgmtail: in file '%s'\n",$file);
                errprt("$pgmtail: function '%s' has no return points\n",
                    $fnx->{fnx_fnc});
                errprt("$pgmtail: suggest recompile with correct options\n");
                if (@$fixlist <= 0) {
                    errprt("$pgmtail: working around because function needs no fixups\n");
                    last;
                }
                if ($fixrtyp ne "P") {
                    errprt("$pgmtail: working around because fixup reg does not need to be saved\n");
                    last;
                }
            }
            # show stats on register usage in function
            $uselook = $fnx->{fnx_used};
            @uselist = sort(keys(%$uselook));
            cmtprt("  USED:\n");
            %avail = %reguse_isbase;
            foreach $sym (@uselist) {
                $val = $uselook->{$sym};
                $typ = $regtmp_type{$sym};
                $typ = sprintf(" (TYPE: %s)",$typ)
                    if (defined($typ));
                cmtprt("    %s used %d%s\n",$sym,$val,$typ);
                $val = $reguse_tobase{$sym};
                delete($avail{$val});
            }
            # show function's available [unused] registers
            @uselist = keys(%avail);
            @uselist = sort(regusesort @uselist);
            if (@uselist > 0) {
                cmtprt("  AVAIL:\n");
                foreach $sym (@uselist) {
                    $typ = $regtmp_type{$sym};
                    $typ = sprintf(" (TYPE: %s)",$typ)
                        if (defined($typ));
                    cmtprt("    %s%s\n",$sym,$typ);
                }
            }
            # skip over any functions that don't need fixing _and_ have a temp
            # register
            if (@$fixlist <= 0 && (! $opt_P)) {
                next if (defined($fixreg));
            }
            msgprt("$pgmtail: function %s\n",$fnx->{fnx_fnc});
            # skip function because we don't have a fixup register but report it
            # here
            unless (defined($fixreg)) {
                $bf = (@$fixlist > 0) ? "FATAL" : "can be ignored -- no fixups needed";
                msgprt("$pgmtail: FIXNOREG (%s)\n",$bf);
                cmtprt("  FIXNOREG (%s)\n",$bf);
                next;
            }
            msgprt("$pgmtail: FIXREG --> %s (TYPE: %s)\n",$fixreg,$fixrtyp);
            cmtprt("  FIXREG --> %s (TYPE: %s)\n",$fixreg,$fixrtyp);
            foreach $fix (@$fixlist) {
                $outoff = $fix->{fix_outoff};
                undef(@fix);
                cmtprt("  FIXOLD %s\n",$outlist[$outoff]);
                # original
                if ($opt_l) {
                    $bf = sprintf("%s,%s",$fix->{fix_lhs},$fixreg);
                    push(@fix,$bf);
                    $bf = sprintf("\tmov\t%s,%s",$fixreg,$fix->{fix_rhs});
                    push(@fix,$bf);
                }
                # use lea
                else {
                    ($xop,$arg) = split(" ",$fix->{fix_lhs});
                    $bf = sprintf("\tlea\t\t%s,%s",$arg,$fixreg);
                    push(@fix,$bf);
                    $bf = sprintf("\t%s\t(%s),%s",$xop,$fixreg,$fix->{fix_rhs});
                    push(@fix,$bf);
                }
                foreach $bf (@fix) {
                    cmtprt("  FIXNEW %s\n",$bf);
                }
                $outlist[$outoff] = [@fix];
            }
            unless ($opt_P) {
                next if ($fixrtyp ne "P");
            }
            # fix the function prolog
            $outoff = $fnx->{fnx_outoff};
            $lhs = $outlist[$outoff];
            $rhs = sprintf("\tpush\t%s",$fixreg);
            $bf = [$lhs,$rhs,""];
            $outlist[$outoff] = $bf;
            # fix the function return points
            $retlist = $fnx->{fnx_retlist};
            foreach $outoff (@$retlist) {
                $rhs = $outlist[$outoff];
                $lhs = sprintf("\tpop\t%s",$fixreg);
                $bf = ["",$lhs,$rhs];
                $outlist[$outoff] = $bf;
            }
        }
        open($xfdst,">$ofile") ||
            sysfault("$pgmtail: unable to open '%s' -- $!\n",$ofile);
        # output all the assembler text
        foreach $bf (@outlist) {
            # ordinary line
            unless (ref($bf)) {
                print($xfdst $bf,"\n");
                next;
            }
            # apply a fixup
            foreach $rhs (@$bf) {
                print($xfdst $rhs,"\n");
            }
        }
        # output all our reasoning as comments at the bottom
        foreach $bf (@cmtprt) {
            if ($bf eq "") {
                print($xfdst $cmtchr,$bf,"\n");
            }
            else {
                print($xfdst $cmtchr," ",$bf,"\n");
            }
        }
        close($xfdst);
        # get difference
        if (defined($opt_D)) {
            system("diff -u $file $ofile >> $opt_D");
        }
        # install fixed/modified file
        {
            last unless ($opt_o || defined($opt_O));
            last if ($fatal);
            msgprt("$pgmtail: installing ...\n");
            rename($ofile,$file);
        }
    }
    # regtmpall -- define all temporary register candidates
    sub regtmpall
    {
        dbgprt(1,"regtmpall: ENTER\n");
        regtmpdef("%r11","T");
        # NOTES:
        # (1) see notes on %r10 in ABI at bottom -- should we use it?
        # (2) a web search on "shared chain" and "x86" only produces 28 results
        # (3) some gcc code uses it as an ordinary register
        # (4) so, use it unless told not to
        regtmpdef("%r10","T")
            unless ($opt_n10);
        # argument registers (a6-a1)
        regtmpdef("%r9","A6");
        regtmpdef("%r8","A5");
        regtmpdef("%rcx","A4");
        regtmpdef("%rdx","A3");
        regtmpdef("%rsi","A2");
        regtmpdef("%rdi","A1");
        # callee preserved registers
        regtmpdef("%r15","P");
        regtmpdef("%r14","P");
        regtmpdef("%r13","P");
        regtmpdef("%r12","P");
        dbgprt(1,"regtmpall: EXIT\n");
    }
    # regtmpdef -- define usable temp registers
    sub regtmpdef
    {
        my($sym,$typ) = @_;
        dbgprt(1,"regtmpdef: SYM sym='%s' typ='%s'\n",$sym,$typ);
        push(@regtmplist,$sym);
        $regtmp_type{$sym} = $typ;
    }
    # regtmploc -- locate temp register to fix problem
    sub regtmploc
    {
        my($fnx,$fixlist) = @_;
        my($sixlist);
        my($uselook);
        my($regrhs);
        my($fixcnt);
        my($coretyp);
        my($reglhs,$regtyp);
        dbgprt(2,"regtmploc: ENTER fnx_fnc='%s'\n",$fnx->{fnx_fnc});
        $sixlist = $fnx->{fnx_sixlist};
        $fixcnt = @$fixlist;
        $fixcnt = 1
            if ($opt_P);
        $uselook = $fnx->{fnx_used};
        foreach $regrhs (@regtmplist) {
            dbgprt(2,"regtmploc: TRYREG regrhs='%s' uselook=%d\n",
                $regrhs,$uselook->{$regrhs});
            unless ($uselook->{$regrhs}) {
                $regtyp = $regtmp_type{$regrhs};
                $coretyp = $regtyp;
                $coretyp =~ s/\d+$//;
                # function uses stack arguments -- we can't push/pop
                if (($coretyp eq "P") && (@$sixlist > 0)) {
                    dbgprt(2,"regtmploc: SIXREJ\n");
                    next;
                }
                if (defined($opt_N)) {
                    dbgprt(2,"regtmploc: TRYREJ opt_N='%s' regtyp='%s'\n",
                        $opt_N,$regtyp);
                    next if ($opt_N =~ /$coretyp/);
                }
                $reglhs = $regrhs;
                last;
            }
        }
        {
            last if (defined($reglhs));
            errprt("regtmploc: unable to locate usable fixup register for function '%s'\n",
                $fnx->{fnx_fnc});
            last if ($fixcnt <= 0);
            $fatal = 1;
        }
        dbgprt(2,"regtmploc: EXIT reglhs='%s' regtyp='%s'\n",$reglhs,$regtyp);
        ($reglhs,$regtyp);
    }
    # regusejoin -- get regex for all registers
    sub regusejoin
    {
        my($reg);
        dbgprt(1,"regusejoin: ENTER\n");
        # rax
        foreach $reg (qw(a b c d))  {
            regusedef($reg,"r_x","e_x","_l","_h");
        }
        #   rdi/rsi
        foreach $reg (qw(d s)) {
            regusedef($reg,"r_i","e_i","_i","_il");
        }
        # rsp/rbp
        foreach $reg (qw(b s)) {
            regusedef($reg,"r_p","e_p");
        }
        foreach $reg (8,9,10,11,12,13,14,15) {
            regusedef($reg,"r_","r_d","r_w","r_b");
        }
        $regusergx = join("|",reverse(sort(@reguse)));
        dbgprt(1,"regusejoin: EXIT regusergx='%s'\n",$regusergx);
    }
    # regusedef -- define all registers
    sub regusedef
    {
        my(@argv) = @_;
        my($mid);
        my($pat);
        my($base);
        $mid = shift(@argv);
        dbgprt(1,"regusedef: ENTER mid='%s'\n",$mid);
        foreach $pat (@argv) {
            $pat = "%" . $pat;
            $pat =~ s/_/$mid/;
            $base //= $pat;
            dbgprt(1,"regusedef: PAT pat='%s' base='%s'\n",$pat,$base);
            push(@reguse,$pat);
            $reguse_tobase{$pat} = $base;
        }
        $reguse_isbase{$base} = 1;
        dbgprt(1,"regusedef: EXIT\n");
    }
    # regusesort -- sort base register names
    sub regusesort
    {
        my($symlhs,$numlhs);
        my($symrhs,$numrhs);
        my($cmpflg);
        {
            ($symlhs,$numlhs) = _regusesort($a);
            ($symrhs,$numrhs) = _regusesort($b);
            $cmpflg = $symlhs cmp $symrhs;
            last if ($cmpflg);
            $cmpflg = $numlhs <=> $numrhs;
        }
        $cmpflg;
    }
    # _regusesort -- split up base register name
    sub _regusesort
    {
        my($sym) = @_;
        my($num);
        if ($sym =~ s/(\d+)$//) {
            $num = $1;
            $num += 0;
            $sym =~ s/[^%]/z/g;
        }
        ($sym,$num);
    }
    # optget -- get options
    sub optget
    {
        my($argv) = @_;
        my($bf);
        my($sym,$val);
        my($dft,%dft);
        $dft{"D"} = "DIFF";
        $dft{"T"} = 1;
        $dft{"l"} = 1;
        $dft{"n10"} = 1;
        $dft{"N"} = "T";
        $dft{"P"} = 1;
        $dft{"q"} = 1;
        $dft{"o"} = 1;
        $dft{"s"} = 1;
        while (1) {
            $bf = $argv->[0];
            $sym = $bf;
            last unless ($sym =~ s/^-//);
            last if ($sym eq "-");
            shift(@$argv);
            {
                if ($sym =~ /([^=]+)=(.+)$/) {
                    ($sym,$val) = ($1,$2);
                    last;
                }
                if ($sym =~ /^(.)(.+)$/) {
                    ($sym,$val) = ($1,$2);
                    last;
                }
                undef($val);
            }
            $dft = $dft{$sym};
            sysfault("$pgmtail: unknown option -- '%s'\n",$bf)
                unless (defined($dft));
            $val //= $dft;
            ${"opt_" . $sym} = $val;
        }
    }
    # cmtprt -- transformation comments
    sub cmtprt
    {
        $_ = shift(@_);
        $_ = sprintf($_,@_);
        chomp($_);
        push(@cmtprt,$_);
    }
    # msgprt -- progress output
    sub msgprt
    {
        printf(STDERR @_);
    }
    # errprt -- show errors
    sub errprt
    {
        cmtprt(@_);
        printf(STDERR @_);
    }
    # sysfault -- abort on error
    sub sysfault
    {
        printf(STDERR @_);
        exit(1);
    }
    # dbgprt -- debug print
    sub dbgprt
    {
        $_ = shift(@_);
        goto &_dbgprt
            if ($opt_T >= $_);
    }
    # _dbgprt -- debug print
    sub _dbgprt
    {
        printf(STDERR @_);
    }