char *line;        // holds copy of entire line
bool copied_line;

%%

^.+  {
       if (!copied_line) {
          free(line);
          line = strdup(yytext);
          copied_line = true;
       }
       yyless(0);
       return TOKEN;
     }

/* ... other tokens ... */

\n   { copied_line = false; return END; }
