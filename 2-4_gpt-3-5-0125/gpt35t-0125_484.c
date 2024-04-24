char *line = NULL;        // holds copy of entire line

%{
#include <stdio.h>
#include <string.h>
extern char *yytext;
extern int yyleng;

void copy_line(const char *str) {
    if (line) {
        free(line);
    }
    line = strdup(str);
}
%}

%option noyywrap

%%

. {
    copy_line(yytext);
    printf("%s", yytext); // You can print the current token here
}

\n {
    printf("\n");
    free(line); // Make sure to free the copied line buffer
}

%%

int main() {
    yyin = stdin;
    yylex();
    return 0;
}
