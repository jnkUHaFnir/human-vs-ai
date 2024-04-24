#include <stdio.h>
#include <string.h>

char* input_line = NULL;

void copy_input_line(const char* text) {
    free(input_line);
    input_line = strdup(text);
}
%{
#include "lexer.h"
%}

%%

.|\n    {
            if (input_line) {
                append_to_buffer(input_line, yytext);
            } else {
                copy_input_line(yytext);
            }
        }
%union {
    char *line_copy; // to pass the line to the parser actions
}

%token <line_copy> TOKEN_IDENTIFIER

%%

program:
    /* some rule using line_copy as necessary */
    ;

