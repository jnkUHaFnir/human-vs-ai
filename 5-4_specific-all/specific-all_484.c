%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];
bool copied_line = false;

void copyLine(const char* input) {
    strncpy(line, input, MAX_LINE_LENGTH);
    copied_line = true;
}

%}

%%

.|\n    {
            if (!copied_line) {
                copyLine(yytext);
            }
            if (yytext[0] == '\n') {
                copied_line = false;
            }
            
            // Process the token normally
            /* Your token processing code here */
        }

%%

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        perror("Error opening file");
        return 1;
    }

    // Set input file
    yyin = inputFile;

    // Start parsing
    yylex();

    fclose(inputFile);

    return 0;
}
