%{
    char *line = NULL;        // holds copy of entire line
    bool copied_line = false;
%}

%x COPY_LINE

%%

^ { copied_line = false; return END; }

<COPY_LINE>[^\n]*\n {
    copied_line = true;
    // Process the entire line stored in yytext here
    return END;
}

. {
    if (!copied_line) {
        BEGIN(COPY_LINE);
        line = strdup(yytext);
    }
}

