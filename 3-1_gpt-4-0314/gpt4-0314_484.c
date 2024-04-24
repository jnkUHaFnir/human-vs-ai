char *line = NULL;     // Buffer to hold the copy of the entire line
size_t line_size = 0;  // Size of the allocated buffer
void copy_line(const char* text, size_t len) {
    if (len + 1 > line_size) { // If the line buffer is too small, we need to resize it.
        free(line);
        line_size = len + 1;
        line = malloc(line_size);
    }
    memcpy(line, text, len);
    line[len] = '\0'; // Null-terminate the copied line.
}
%%

\n       { copy_line(yytext, yyleng); return END; }
^.|\n    { }
.        { /* ... other tokens ... */ }
