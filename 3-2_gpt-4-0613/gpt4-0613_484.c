char *line_start = 0;
char *line_end = 0;

%%

\n { line_start = yytext + yyleng; line_end = line_start; /* move to next line */ }
. { line_end++; /* match any single character, move the line end forward */ }


void print_error(char *msg) {
    int line_length = line_end - line_start;
    char *line_copy = malloc((line_length + 1) * sizeof *line_copy);
    strncpy(line_copy, line_start, line_length);
    /* ensure null termination */
    line_copy[line_length] = '\0';

    /* ... print line, caret, and error message ... */

    free(line_copy);
}
