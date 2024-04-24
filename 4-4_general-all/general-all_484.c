%{
char *line = NULL;          // holds copy of entire line
int line_size = 0;          // current size of the line buffer
bool copied_line = false;   // flag to track whether the line has been copied

// Custom function to append text to the line buffer
void append_to_line(const char *text) {
    int text_len = strlen(text);
    line_size += text_len;
    line = (char *)realloc(line, line_size + 1);
    strcat(line, text);
}

%}

%option noyywrap

%%

\n {
    copied_line = false;
    return END;
}

. {
    if (!copied_line) {
        line_size = 0;
        if (line) {
            free(line);
            line = NULL;
        }
        copied_line = true;
    }
    append_to_line(yytext);
    return OTHER_TOKEN;
}

%%

int main() {
    yylex();
    // Other processing here
    if (line) {
        printf("Copied line: %s\n", line);
        free(line);
    }
    return 0;
}
