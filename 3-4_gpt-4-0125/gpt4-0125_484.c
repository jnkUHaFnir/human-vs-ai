%{
#include <string.h>
#include <stdlib.h>

// Assuming line is a dynamic array/buffer.
char *line = NULL;
size_t line_cap = 0;    // Capacity of the line buffer
size_t line_len = 0;    // Current length of the line

void ensure_line_capacity(size_t needed) {
    if (needed > line_cap) {
        line_cap = needed + 256; // Increase capacity with some buffer
        line = (char *)realloc(line, line_cap);
        if (!line) {
            // Error handling for memory allocation failure
            exit(1);
        }
    }
}

%}

%option noyywrap

%x CAPTURING_LINE

%%

<INITIAL>{
    "\n" {
        // Switch to CAPTURING_LINE state at the beginning of a line
        BEGIN(CAPTURING_LINE);
        line_len = 0;
        ensure_line_capacity(1);
        line[0] = '\0';
    }
}

<CAPTURING_LINE>{
    [^\n]+ {
        // Append text to line buffer
        ensure_line_capacity(line_len + yyleng + 1);
        memcpy(line + line_len, yytext, yyleng);
        line_len += yyleng;
        line[line_len] = '\0'; // Ensure null-termination
    }
    "\n" {
        // When the newline is reached, switch back to INITIAL state
        BEGIN(INITIAL);

        // Line is complete; can now be used for error reporting if needed

        // Process the newline token as needed
        // E.g., return TOKEN;
    }
}
