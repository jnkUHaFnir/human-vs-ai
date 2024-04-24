#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    int i = 0, j = 0, k = 0;
    int size = strlen(text);

    if (size >= 16) {
        // If text is 16 characters or longer, return a duplicate of text
        char* final = (char*)malloc((size + 1) * sizeof(char)); // Allocate memory for the final string
        strcpy(final, text); // Copy text to the final string
        return final;
    }

    // Calculate the number of spaces needed to center the text
    int diff = 16 - size;
    int left_spaces = diff / 2;
    int right_spaces = diff - left_spaces;

    char spaces[17]; // Leave one extra space for the null terminator
    for (j = 0; j < left_spaces; j++) {
        spaces[j] = ' ';
    }
    spaces[left_spaces] = '\0';

    // Create the centered text with spaces on both sides
    char* centered_text = (char*)malloc(17 * sizeof(char)); // Allocate memory for the centered text
    strcpy(centered_text, spaces); // Copy left spaces
    strcat(centered_text, text); // Append text
    strcat(centered_text, spaces); // Append right spaces

    return centered_text;
}

int main() {
    char input[] = "This is a longer text to center";

    char* centered = align_text(input);
    printf("Centered text:\n%s\n", centered);

    free(centered); // Free dynamically allocated memory
    return 0;
}
