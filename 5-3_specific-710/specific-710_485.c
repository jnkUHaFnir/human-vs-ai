#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];        // buffer to hold copy of entire line
bool copied_line = false;

%%

[^ \t\n]+  {
       if ( !copied_line ) {
          strncpy(line, yytext, MAX_LINE_LENGTH);
          copied_line = true;
       }
       // Process the token as needed
     }

\n   { 
       copied_line = false;
       return END;
     }

%%

int main() {
    // Initialize the lexer here

    // Test the lexer with input
    yy_scan_string("This is a test line\n");

    // Call yylex to trigger token processing
    yylex();

    // Any further processing

    return 0;
}
