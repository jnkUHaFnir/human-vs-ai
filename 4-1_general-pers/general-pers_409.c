#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int j, k;
    char *doubled = NULL;
    char *output[500]; // Assuming output is an array of strings

    for (j = 1; j < 500; j++) {
        doubled = (char *)malloc(strlen(output[j]) * 2 + 1); // Allocate memory for doubled string
        
        if (doubled == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            return 1;
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

        free(doubled); // Free the dynamically allocated memory
        doubled = NULL; // Reset the pointer to avoid double free
    }

    return 0;
}
