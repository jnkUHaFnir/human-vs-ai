#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_number = 1;
char line_buffer[1024]; // Adjust the size as needed

%%

^. { 
    if (line_number == 1) {
        memset(line_buffer, 0, sizeof(line_buffer)); // Clear the buffer
    }
    strcat(line_buffer, yytext);
    if (yytext[0] == '\n') {
        line_number++;
    }
    return *yytext; 
}

%%

int main() {
    yylex();
    printf("Line %d: %s\n", line_number, line_buffer);
    return 0;
}
