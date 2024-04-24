%option yylineno

char *line = NULL;

%%

\n       {
             if (line) {
                 free(line);
                 line = NULL;
             }
             line = strdup(yytext);
             /* Do something with the line or simply continue */
             /* Optionally, you can also reset line to NULL after the action is taken */
         }

.|\n      { /* This will match any other character or newline */ }

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s at line %d\n", msg, yylineno);
    fprintf(stderr, "%s\n", line);
    fprintf(stderr, "%*s\n", (int)(yyleng), "^"); // Adjust for the length of yytext
}

int main(int argc, char **argv) {
    // ... your main code ...

    yyparse();

    free(line); // Clean up at the end.
    return 0;
}

// Other necessary functions and rules
