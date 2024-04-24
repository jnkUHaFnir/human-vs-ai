#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line_buffer[1024]; // Assuming a maximum line length of 1023 characters

%%

^.+  {
       strcpy(line_buffer, yytext);
     }

/* ... other tokens ... */

\n   { return END; }
