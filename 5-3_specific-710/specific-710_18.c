#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* align_text(const char* text) {
    const int lineLength = 16;
    const int numLines = 8;

    char* final = (char*)malloc(lineLength * numLines + numLines); // +1 for each '\n' character

    int totalLen = strlen(text);
    int remainingLen = totalLen;

    int line = 0;
    int offset = 0;

    while (remainingLen > 0 && line < numLines) {
        int spaces = (lineLength - remainingLen) / 2; // Calculate number of spaces needed to center the text
        if (spaces < 0) spaces = 0;

        int charsToCopy = lineLength - 2 * spaces; // Determine how many characters to copy to this line
        if (charsToCopy > remainingLen) charsToCopy = remainingLen;

        // Add spaces to center the text
        for (int i = 0; i < spaces; i++) {
            final[offset++] = ' ';
        }

        // Copy characters to the final output
        strncpy(final + offset, text + totalLen - remainingLen, charsToCopy);
        offset += charsToCopy;

        // Add spaces to center the text
        for (int i = 0; i < spaces; i++) {
            final[offset++] = ' ';
        }

        final[offset++] = '\n'; // Add a new line character
        remainingLen -= charsToCopy;
        line++;
    }

    final[offset] = '\0'; // Null-terminate the string

    return final;
}

int main() {
    const char* text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

    char* centeredText = align_text(text);

    printf("%s\n", centeredText);

    free(centeredText);

    return 0;
}
