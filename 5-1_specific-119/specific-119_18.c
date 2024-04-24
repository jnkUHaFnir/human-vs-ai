#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    int i = 0, j = 0;
    int diff, modulo;
    int size = strlen(text);
    char space[16];
    char tmp[16] = "";
    char* final = NULL;

    if (size >= 16) {
        return text; // Do not modify text longer than 16 characters per line
    }

    diff = 16 - size;
    modulo = diff % 2;

    if (modulo == 0) {
        int space_count = diff / 2;
        for (j = 0; j < space_count; j++) {
            space[j] = ' ';
        }
        space[j] = '\0';
    } else {
        int space_count = diff / 2;
        for (j = 0; j < space_count; j++) {
            space[j] = ' ';
        }
        space[j] = '\0';
        strcat(tmp, space);
    }

    strcat(tmp, text);
    strcat(tmp, space);

    final = (char*)malloc(17 * sizeof(char)); // Allocate memory for 16 characters + '\0'
    if (final) {
        strcpy(final, tmp);
    } else {
        fprintf(stderr, "Memory allocation failed.");
    }

    return final;
}

int main() {
    char* text1 = "Hello";
    char* text2 = "This is a longer text to be aligned";

    // Align single line text
    char* aligned_text1 = align_text(text1);
    printf("%s\n", aligned_text1);
    free(aligned_text1);
    
    // Align multi-line text
    char* aligned_text2 = align_text(text2);
    printf("%s\n", aligned_text2);
    free(aligned_text2);

    return 0;
}
