#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    int size = strlen(text);
    char* final = NULL;
    char* line = (char*)malloc(17 * sizeof(char)); // 16 characters + '\0'
    line[0] = '\0';

    if (size <= 16) {
        // For single line, which is less than or equal to 16 characters
        int diff = 16 - size;
        for (int i = 0; i < diff / 2; i++) {
            strcat(line, " "); // add leading spaces
        }
        strcat(line, text);
        while (strlen(line) < 16) {
            strcat(line, " "); // add trailing spaces if necessary
        }
    } else {
        // For text that spans multiple lines
        final = (char*)malloc(size + (size / 16 + 1) * 2); // Allocate with additional space for new lines and potential padding
        final[0] = '\0';
        char* token = strtok(text, " ");
        while (token != NULL) {
            if (strlen(line) + strlen(token) > 15) { // Check if new word fits in line
                // Center align current line
                int lineLength = strlen(line);
                int diff = 16 - lineLength;
                char paddedLine[17];
                int padding = diff / 2;
                snprintf(paddedLine, 17, "%*s%s%*s", padding, "", line, diff - padding, "");
                strcat(final, paddedLine);
                strcat(final, "\n"); // Add new line
                strcpy(line, token); // Start new line with current token
                strcat(line, " ");
            } else {
                strcat(line, token);
                strcat(line, " ");
            }
            token = strtok(NULL, " ");
        }

        // Align the last line
        int lineLength = strlen(line);
        if (lineLength > 0) { // Omit if no content
            line[lineLength-1] = '\0'; // Remove the trailing space
            int diff = 16 - strlen(line);
            char paddedLine[17];
            int padding = diff / 2;
            snprintf(paddedLine, 17, "%*s%s%*s", padding, "", line, diff - padding, "");
            strcat(final, paddedLine);
        }
    }

    if (final == NULL) { // For single line case
        final = (char*)malloc(strlen(line) + 1); // +1 for '\0'
        strcpy(final, line);
    }

    free(line);
    return final;
}

int main() {
    char* text = "This is a sample text that spans multiple lines on a 16x8 screen. Let's see how it aligns!";
    char* centeredText = align_text(text);
    printf("%s\n", centeredText);
    free(centeredText);
}
