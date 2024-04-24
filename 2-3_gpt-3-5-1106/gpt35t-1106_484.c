%{
char *line;        // holds copy of entire line
int line_length;
%}

%x COPY_LINE

%%

<INITIAL>.+  {
       line = strdup(yytext);
       line_length = yyleng;
       BEGIN(COPY_LINE);
     }

<COPY_LINE>.|\n  {
       // Do nothing, just continue capturing the entire line
     }

<COPY_LINE><<EOF>> {
       // Handle end of file while capturing the line
     }

<COPY_LINE>\n   {
       // Handle end of line, then return to INITIAL state and free the copied line
       free(line);
       line = NULL;
       line_length = 0;
       BEGIN(INITIAL);
       return END;
     }

/* ... other tokens ... */

%%

int yywrap() {
    return 1; // Report end of input
}
