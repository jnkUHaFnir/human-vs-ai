%{
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *line = NULL;    // holds copy of entire line
bool copied_line = false;
%}

%option noyywrap
%array

%%

.|\n  {
        if (!copied_line) {
            free(line);
            line = strdup(yytext);
            copied_line = true;
        }
        REJECT;
     }
     
\n    {
        copied_line = false;
        return END;
     }

