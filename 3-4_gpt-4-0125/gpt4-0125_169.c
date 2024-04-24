#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024 // Define the maximum line length

int main() {
    FILE *f = fopen("textfile", "r");
    if (!f) {
        printf("Error opening file\n");
        return 1;
    }

    char line1[MAX_LINE_LENGTH] = {0}; // Initialize the line buffers
    char line2[MAX_LINE_LENGTH] = {0};
    char *lines[] = {line1, line2}; // Array of pointers to line buffers
    int currentLine = 0;
    int i = 0; // Index for character position in line

    int ch; // int, not char, to handle EOF
    while ((ch = fgetc(f)) != EOF && currentLine < 2) { // Read until EOF or both lines are read
        if (ch == '\n') { // End of line
            lines[currentLine][i] = '\0'; // Null-terminate the current line
            currentLine++;
            i = 0; // Reset character position index for the next line
            continue;
        }

        if (i < MAX_LINE_LENGTH - 1) { // Check to avoid buffer overflow
            lines[currentLine][i++] = (char)ch;
        } else {
            // Handle long line error or truncate the line
            printf("Line is too long. Increasing MAX_LINE_LENGTH may be required.\n");
            break; // Exit loop or you might want to truncate lines instead
        }
    }

    if (currentLine < 2) {
        lines[currentLine][i] = '\0'; // Also null-terminate the last read line if it is not followed by a newline
    }

    fclose(f);

    printf("Line 1: %s\n", line1);
    printf("Line 2: %s\n", line2);

    return 0;
}
