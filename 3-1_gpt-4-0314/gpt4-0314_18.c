#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(const char* text) {

    int i = 0, j = 0, k;
    int diff;
    int size = strlen(text);
    char space[17]; // Increased the size by 1 for the null terminator
    char tmp[17];
    char median[150] = ""; // Added initialization to avoid garbage values
    char* final;

    // Base case: text length is less than or equal to 16
    if (size <= 16) {
        diff = 16 - size;

        for (j = 0; j < diff / 2; j++)
            space[j] = ' ';
        space[j] = '\0';

        strcat(median, space);
        strcat(median, text);
        strcat(median, space);

        final = (char*)malloc((strlen(median) + 1) * sizeof(char)); // Added '+1' to include space for the null terminator
        strcpy(final, median);
        return final;
    }
    // Else case: text length is more than 16, align text line by line
    else {
        char* remaining_text = NULL;

        // Find the last space within the 16 characters limit
        for (i = 15; i >= 0; i--) {
            if (text[i] == ' ' || text[i] == '\n') {
                strncpy(tmp, text, i);
                tmp[i] = '\0';
                break;
            }
        }

        // If no space is found, limit the line to 16 characters
        if (i < 0) {
            strncpy(tmp, text, 16);
            tmp[16] = '\0';
            i = 15; // Set i to 15 to point at the last character
        }

        // If text is not ending with the line break
        if (text[i] != '\n')
            remaining_text = align_text(text + i + 1);
        else
            remaining_text = align_text(text + i);

        strncpy(median, align_text(tmp), 17);
        median[16] = '\n';
        strcpy(median + 17, remaining_text);

        final = (char*)malloc((strlen(median) + 1) * sizeof(char));
        strcpy(final, median);
        free(remaining_text);
        return final;
    }
}

int main() {
    char* result = align_text("Write a multi-line text longer than 16 characters.");
    printf("%s\n", result);
    free(result);
    return 0;
}
