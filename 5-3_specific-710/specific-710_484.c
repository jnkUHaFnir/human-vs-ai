char *line_buffer = NULL;   // buffer to hold the entire line
int line_buffer_size = 0;   // size of the line buffer
int line_length = 0;        // length of the current line

%%

. {
    if (!line_buffer) {
        line_buffer_size = 1024;  // initial size of the buffer
        line_buffer = (char *)malloc(line_buffer_size);
        if (!line_buffer) {
            // handle allocation failure
        }
    }

    line_buffer[line_length++] = yytext[0];

    if (yytext[0] == '\n') {
        line_buffer[line_length] = '\0';  // null-terminate the line
        // Process the complete line stored in line_buffer
        // For example, you can store it in a separate data structure for error reporting
        line_length = 0;  // reset line length for the next line
    }

    return yytext[0];  // return the character read
}

%%

int main() {
    // Initialize lexer and start parsing
    yylex();

    // Free line buffer memory
    free(line_buffer);

    return 0;
}
