%{
char *line = NULL;          // holds copy of entire line
size_t line_size = 0;
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

<COPY_LINE>.+ {
    // Continue copying the line
    size_t new_size = line_size + strlen(yytext);
    line = realloc(line, new_size + 1);
    strcat(line, yytext);
}

<COPY_LINE>\n {
    copied_line = false;
    BEGIN(INITIAL);
    return END;
}

/* ... other tokens ... */
