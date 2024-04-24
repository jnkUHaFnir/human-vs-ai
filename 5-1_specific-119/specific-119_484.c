#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];  // buffer to hold a line
bool copied_line = false;

%%

.|\n  {
        if (!copied_line) {
            // Store the entire line into the buffer
            strcpy(line, yytext);
            copied_line = true;
        }
        if (*yytext == '\n') {
            copied_line = false;
        }
        return *yytext; // Return the character read
     }

/* ... other tokens ... */

%%

int main() {
    // Initialize line buffer
    line[0] = '\0';

    // Read input line by line until EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        yylex();
    }

    return 0;
}
