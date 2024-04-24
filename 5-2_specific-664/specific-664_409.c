#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* output[500] = { "dog", "cat", "bird", "dog", "dog", "cat", "dog" };
    int j, k;
    char *doubled;

    for (j = 1; j < 500; j++) {
        doubled = malloc(2 * strlen(output[j]) + 1); // Allocate memory for doubled string
        if (doubled == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        strcpy(doubled, output[j]);
        strcat(doubled, doubled);

        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                output[j] = doubled;
            }
            if (strcmp(output[k], doubled) == 0) {
                output[j] = '\0';
            }
        }
    }

    for (int i = 0; i < 500; i++) {
        if (output[i] != NULL) {
            printf("%s\n", output[i]);
        }
    }

    // Free dynamically allocated memory
    for (int i = 1; i < 500; i++) {
        free(output[i]);
    }

    return 0;
}
