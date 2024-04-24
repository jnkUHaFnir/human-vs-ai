%{
#define MAX_LINE_LENGTH 1024
char line[MAX_LINE_LENGTH];
int line_length = 0;
%}

%option noyywrap

%%

. {
    if (line_length < MAX_LINE_LENGTH - 1) {
        line[line_length++] = yytext[0];
        line[line_length] = '\0'; // Null-terminate the string
    }
    ECHO;
}

\n {
    line_length = 0;
    return END;
}

%%

int main() {
    yylex();
    return 0;
}
