#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of a string

int main() {
    int j, k;
    char output[500][MAX_LENGTH]; // Array of strings
    char *doubled = malloc(MAX_LENGTH * 2); // Allocate memory for doubled string

    if (doubled == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (j = 0; j < 500; j++) {
        doubled[0] = '\0'; // Reset doubled string at each iteration
        strcpy(doubled, output[j]);
        strcat(doubled, doubled);
        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                strcpy(output[j], doubled); // Copy doubled string to output[j]
            }
            if (strcmp(output[k], doubled) == 0) {
                output[j][0] = '\0'; // Set the first character to '\0' to mark the string as deleted
            }
        }
    }

    free(doubled); // Free dynamically allocated memory

    // Printing the processed output
    for (j = 0; j < 500; j++) {
        if (output[j][0] != '\0') {
            printf("%s\n", output[j]);
        }
    }

    return 0;
}
