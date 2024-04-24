%option noyywrap

%{
#include <stdlib.h>
#include <string.h>

char *current_line = NULL;
size_t line_capacity = 0;
size_t line_length = 0;

void add_to_line(const char* text) {
    size_t text_length = strlen(text);
    while(line_length + text_length >= line_capacity) {
        line_capacity = line_capacity ? line_capacity * 2 : 128;
        current_line = realloc(current_line, line_capacity);
    }
    memcpy(current_line + line_length, text, text_length);
    line_length += text_length;
    current_line[line_length] = '\0'; // Null-terminate the string
}

void reset_line() {
    line_length = 0;
    if(current_line) current_line[0] = '\0';
}
%}

%%

\n  { add_to_line(yytext); /* Process the line if needed, then reset for the new line */ reset_line(); return END; }
.   { add_to_line(yytext); }

%%
