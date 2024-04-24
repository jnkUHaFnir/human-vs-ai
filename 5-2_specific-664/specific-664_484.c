#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];  // buffer to hold the current line
bool copied_line = false;

%%

^.*\n  {
       if (!copied_line) {
           strncpy(line, yytext, MAX_LINE_LENGTH);
           line[MAX_LINE_LENGTH - 1] = '\0';  // Ensure the buffer is null-terminated
           copied_line = true;
       }
     }

/* ... other tokens ... */

\n   { copied_line = false; return END; }
