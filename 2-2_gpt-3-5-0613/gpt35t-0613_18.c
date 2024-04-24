#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    int i = 0, j = 0;
    int size = strlen(text);
    char median[150] = "";

    if (size >= 16) {
        // If the text is equal or longer than 16 characters, return as it is
        return text;
    } else {
        int diff = 16 - size;
        int leftPadding = diff / 2;
        int rightPadding = diff - leftPadding;
        for (i = 0; i < leftPadding; i++) {
            median[i] = ' ';
        }
        strcat(median, text);
        for (i = leftPadding + size; i < leftPadding + size + rightPadding; i++) {
            median[i] = ' ';
        }
        median[leftPadding + size + rightPadding] = '\0';
    }

    char* final = (char*)malloc((strlen(median) + 1) * sizeof(char));
    strcpy(final, median);
    return final;
}

int main() {
    char* text = "Hello world!";
    char* alignedText = align_text(text);
    printf("%s\n", alignedText);
    free(alignedText);

    return 0;
}
