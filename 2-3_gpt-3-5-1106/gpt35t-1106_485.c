%{
char *line = NULL;        // holds copy of entire line
bool copied_line = false;
%}

%x COPY_LINE

%%

<INITIAL>.+  {
    if (!copied_line) {
        free(line);
        line = strdup(yytext);
        copied_line = true;
    }
    BEGIN(COPY_LINE);
}

<COPY_LINE>.+  {
    // Continue copying the line
    line = realloc(line, strlen(line) + strlen(yytext) + 1);
    strcat(line, yytext);
}

<COPY_LINE>\n  {
    // End of line, return to initial state
    copied_line = false;
    BEGIN(INITIAL);
    return END;
}

/* ... other tokens ... */

%%
