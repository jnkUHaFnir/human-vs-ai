char *line = NULL; // holds copy of entire line
bool copied_line;

%%

\n {
    if(!copied_line) {
        if(line != NULL) {
		    free(line);
        }
        line = strndup(yytext, yyleng);
        copied_line = true;
    }
    return END;
}

.|\r {
    // ... process other characters and tokens ...
}

%%

int yywrap() { return 1; }
