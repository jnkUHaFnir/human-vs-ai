char *line;        // holds copy of entire line
char *current_pos; // current position in the buffer
char *token_start;  // start of the current token

%%

^.*$  {
       line = strdup(yytext);
       current_pos = line;
       token_start = line;
       return END;
     }

. {
   return *yytext;
}

