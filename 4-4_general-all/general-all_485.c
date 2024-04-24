#define MAX_LINE_LENGTH 1024

char line[MAX_LINE_LENGTH];  // buffer to hold the current input line
int line_len = 0;            // length of the current input line
bool copying_line = false;   // flag to indicate if currently copying a line

%%

^.{0,MAX_LINE_LENGTH}  {
    if (!copying_line) {
        line_len = 0;
        copying_line = true;
    }
    
    if (line_len + yyleng > MAX_LINE_LENGTH) {
        // Line too long, handle error or truncate line
    } else {
        memcpy(line + line_len, yytext, yyleng);
        line_len += yyleng;
    }
}

.  {
    if (copying_line) {
        // Continue copying the line
        if (line_len + yyleng > MAX_LINE_LENGTH) {
            // Line too long, handle error or truncate line
        } else {
            memcpy(line + line_len, yytext, yyleng);
            line_len += yyleng;
        }
    }
}

\n   {
    if (copying_line) {
        line[line_len] = '\0';  // Null-terminate the line
        copying_line = false;
        return END;
    }
}

/* ... other tokens ... */
