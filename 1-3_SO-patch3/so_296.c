    #!/usr/bin/perl
    # pebsfix/pebsfixup -- fix assembler source for PEBS usage
    #
    # command line options:
    #   "-d" -- show differences
    #   "-o" -- overwrite input file
    #   "-q" -- suppress warnings
    #
    # command line arguments:
    #   1-- list of .s files to process
    #       for a given file "foo.s", output is to "foo.TMP"
    #       if (-o is given, "foo.TMP" is renamed to "foo.s")
    #
    # suggested usage:
    #   change build to produce .s files
    #   FROM:
    #     cc [options] -c foo.c
    #   TO:
    #     cc [options] -c -s foo.c
    #     pebsfixup -o foo.s
    #     cc -c foo.s
    #
    # suggested compiler options:
    #   (1) use "-O1" or "-fno-optimize-sibling-calls"
    #   (2) use "-mno-omit-leaf-frame-pointer"
    #pragma pgmlns
    ###use strict;
    master(@ARGV);
    exit(0);
    # master -- master control
    sub master
    {
        my(@argv) = @_;
        my($file);
        my($bf);
        $pgmtail = "pebsfixup";
        optget(\@argv);
        # temporary registers
        # FIXME/CAE -- see notes on %r10 in ABI at bottom -- should we use it?
        regdef("%r11","T");
        ###regdef("%r10","T");
        # argument registers (a6-a1)
        regdef("%r9","A6");
        regdef("%r8","A5");
        regdef("%rcx","A4");
        regdef("%rdx","A3");
        regdef("%rsi","A2");
        regdef("%rdi","A1");
        # callee preserved registers
        regdef("%r15","P");
        regdef("%r14","P");
        regdef("%r13","P");
        regdef("%r12","P");
        if ($opt_d) {
            $diff = "DIFF";
            unlink($diff);
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
            dofile($file);
        }
        if ($opt_d) {
            exec("less",$diff);
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
        my($ix);
        my($sym,$val);
        my(%sym_type);
        my($fnc,$fnx,%fnx_lookup,@fnxlist);
        my($retlist);
        my($uselook,@uselist);
        my($fixreg,$fixrtyp);
        my($fix,$fixlist);
        my($fixtot);
        my(@fix);
        my(@outlist);
        my($relaxflg);
        my($cmtchr);
        local($fatal);
        local(@cmtprt);
        msgprt("\n")
            if ($sepflg);
        $sepflg = 1;
        msgprt("$pgmtail: processing %s ...\n",$file);
        $cmtchr = "#";
        cmtprt("%s\n","-" x 78);
        cmtprt("FILE: %s\n",$file);
        $ofile = $file;
        sysfault("$pgmtail: bad suffix -- file='%s'\n",$file)
            unless ($ofile =~ s/[.]s$//);
        $ofile .= ".TMP";
        open($xfsrc,"<$file") ||
            sysfault("$pgmtail: unable to open '%s' -- $!\n",$file);
        $lno = 0;
        while ($bf = <$xfsrc>) {
            chomp($bf);
            $bf =~ s/\s+$//;
            $outoff = $lno;
            ++$lno;
            push(@outlist,$bf);
            # look for ".type blah, @function"
            if ($bf =~ /^\s+[.]type\s+([^,]+),\s+(\S+)/) {
                ($sym,$val) = ($1,$2);
                $val =~ s/^\@//;
                $sym_type{$sym} = $val;
                cmtprt("TYPE: %s --> %s\n",$sym,$val);
                next;
            }
            # look for "able:"
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
                next;
            }
            # remember all used registers
            while ($bf =~ /%[er](.x|\d+)/gp) {
                $sym = ${^MATCH};
                $sym =~ s/^%e/%r/;
                $uselook->{$sym} += 1;
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
            # ... and "%rax"
            $rhs = substr($bf,$ix + 1);
            $rhs =~ s/^\s+//;
            # target must be a register
            # FIXME/CAE -- the "e" may be overkill for x86_64
            next unless ($rhs =~ /%[er](.x|\d+)/);
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
            # get the fixup register
            ($fixreg,$fixrtyp) = regfix($fnx);
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
            foreach $sym (@uselist) {
                $val = $uselook->{$sym};
                $typ = $rgx_type{$sym};
                $typ = sprintf(" (TYPE: %s)",$typ)
                    if (defined($typ));
                cmtprt("  %s used %d%s\n",$sym,$val,$typ);
            }
            # skip over any functions that don't need fixing
            next if (@$fixlist <= 0);
            # skip function because we don't have a fixup register
            next unless (defined($fixreg));
            cmtprt("  FIXREG --> %s (TYPE: %s)\n",$fixreg,$fixrtyp);
            foreach $fix (@$fixlist) {
                $outoff = $fix->{fix_outoff};
                undef(@fix);
                cmtprt("  FIXOLD %s\n",$outlist[$outoff]);
                $bf = sprintf("%s,%s",$fix->{fix_lhs},$fixreg);
                push(@fix,$bf);
                $bf = sprintf("\tmov\t%s,%s",$fixreg,$fix->{fix_rhs});
                push(@fix,$bf);
                foreach $bf (@fix) {
                    cmtprt("  FIXNEW %s\n",$bf);
                }
                $outlist[$outoff] = [@fix];
            }
            next unless ($fixrtyp eq "P");
            # fix the function prolog
            $outoff = $fnx->{fnx_outoff};
            $lhs = $outlist[$outoff];
            $rhs = sprintf("\tpush\t%s\n",$fixreg);
            $bf = [$lhs,$rhs];
            $outlist[$outoff] = $bf;
            # fix the function return points
            $retlist = $fnx->{fnx_retlist};
            foreach $outoff (@$retlist) {
                $rhs = $outlist[$outoff];
                $lhs = sprintf("\tpop\t%s\n",$fixreg);
                $bf = [$lhs,$rhs];
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
        if ($opt_d) {
            system("diff -u $file $ofile >> $diff");
        }
        # install fixed/modified file
        {
            last unless ($opt_o);
            last if ($fatal);
            msgprt("$pgmtail: installing ...\n");
            rename($ofile,$file);
        }
    }
    # regdef -- define usable temp registers
    sub regdef
    {
        my($sym,$typ) = @_;
        push(@rgxlist,$sym);
        $rgx_type{$sym} = $typ;
    }
    # regfix -- find temp register to fix problem
    sub regfix
    {
        my($fnx) = @_;
        my($uselook);
        my($regrhs);
        my($fixlist);
        my($reglhs,$regtyp);
        $uselook = $fnx->{fnx_used};
        foreach $regrhs (@rgxlist) {
            unless ($uselook->{$regrhs}) {
                $reglhs = $regrhs;
                $regtyp = $rgx_type{$reglhs};
                last;
            }
        }
        {
            last if (defined($reglhs));
            errprt("regfix: unable to locate usable fixup register\n");
            $fixlist = $fnx->{fnx_fixlist};
            last if (@$fixlist <= 0);
            $fatal = 1;
        }
        ($reglhs,$regtyp);
    }
    # optget -- get options
    sub optget
    {
        my($argv) = @_;
        my($sym,$val);
        while (1) {
            $sym = $argv->[0];
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
                $val = 1;
            }
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
    # ------------------------------------------------------------------------------
    # x86 ABI register usage in function calls:
    #
    #   %rax temporary register;
    #        with variable arguments passes information about the number of vector
    #        registers used; 1st return register
    #   Preserved: No
    #
    #   %rbx callee-saved register; optionally used as base pointer
    #   Preserved: Yes
    #
    #   %rcx used to pass 4th integer argument to functions
    #   Preserved: No
    #
    #   %rdx used to pass 3rd argument to functions; 2nd return register
    #   Preserved: No
    #
    #   %rsp stack pointer
    #   Preserved: Yes
    #
    #   %rbp callee-saved register; optionally used as frame pointer
    #   Preserved: Yes
    #
    #   %rsi used to pass 2nd argument to functions
    #   Preserved: No
    #
    #   %rdi used to pass 1st argument to functions
    #   Preserved: No
    #
    #   %r8 used to pass 5th argument to functions
    #   Preserved: No
    #
    #   %r9 used to pass 6th argument to functions
    #   Preserved: No
    #
    #   %r10 temporary register, used for passing a function’s static chain pointer
    #   Preserved: No
    #
    #   %r11 temporary register
    #   Preserved: No
    #
    #   %r12-r15 callee-saved registers
    #   Preserved: Yes
    #
    #   %xmm0–%xmm1 used to pass and return floating point arguments
    #   Preserved: No
    #
    #   %xmm2–%xmm7 used to pass floating point arguments
    #   Preserved: No
    #
    #   %xmm8–%xmm15 temporary registers
    #   Preserved: No
    #
    #   %mmx0–%mmx7 temporary registers
    #   Preserved: No
    #
    #   %st0,%st1 temporary registers; used to return long double arguments
    #   Preserved: No
    #
    #   %st2–%st7 temporary registers
    #   Preserved: No
    #
    #   %fs Reserved for system (as thread specific data register)
    #   Preserved: No
    #
    #   mxcsr SSE2 control and status word partial
    #   x87 SW x87 status word
    #   Preserved: No
    #
    #   x87 CW x87 control word
    #   Preserved: Yes