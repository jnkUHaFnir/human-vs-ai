#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];  // holds copy of entire line
int line_length = 0;

%%

^.*\n {
    line_length = yyleng - 1;  // excluding the newline character
    if (line_length > MAX_LINE_LENGTH - 1) {
        // Handle error: line too long for buffer
        // You may also consider dynamically allocating memory here
    } else {
        strncpy(line, yytext, line_length);
        line[line_length] = '\0'; // Null-terminate the copied line
    }
}

/* other tokens */

\n {
    line[0] = '\0';  // Reset line buffer for next line
    line_length = 0;
    return END; 
}
