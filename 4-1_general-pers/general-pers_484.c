char *line = NULL; // Holds copy of entire line
int line_size = 0; // Tracks the size of the line buffer
bool copied_line = false;

%%

^.* {
    if (!copied_line) {
        line_size = yyleng; // Initialize line size
        line = (char *)realloc(line, line_size + 1);
        if (!line) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        memcpy(line, yytext, yyleng);
        line[yyleng] = '\0'; // Null-terminate the line
        copied_line = true;
    }
}

\n {
    copied_line = false;
    return END;
}

. { /* Ignore other characters */ }
