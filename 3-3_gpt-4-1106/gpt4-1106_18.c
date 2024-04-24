#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* center_text(const char* text) {
    const int screenWidth = 16;
    int i, lineLength;
    size_t size = strlen(text);
    char* centeredText = malloc((size + 1) * sizeof(char)); // buffer for the resulting text
    if (!centeredText) {
        return NULL; // If malloc fails, return NULL
    }
    strncpy(centeredText, text, size + 1); // Copy original text

    char* line = strtok(centeredText, "\n");
    char* finalText = malloc((size + size / screenWidth + 1) * sizeof(char)); // extra space for new lines
    if (!finalText) {
        free(centeredText);
        return NULL; // If malloc fails, clean up and return NULL
    }
    finalText[0] = '\0';

    while (line != NULL) {
        lineLength = strlen(line);
        if (lineLength < screenWidth) {
            char paddedLine[screenWidth + 1];
            int padding = (screenWidth - lineLength) / 2;
            sprintf(paddedLine, "%*s%s%*s", padding, "", line, screenWidth - lineLength - padding, "");
            strcat(finalText, paddedLine);
        } else {
            strcat(finalText, line); // More than one line case not handled in this code
        }
        strcat(finalText, "\n");
        line = strtok(NULL, "\n");
    }

    free(centeredText);
    return finalText;
}

int main() {
    char text[] = "This is a test string that is longer than 16 characters";
    char* centered = center_text(text);

    if (centered) {
        printf("%s", centered);
        free(centered);
    }

    return 0;
}
