#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *output[500]; // Assuming output is defined elsewhere in your code

    int j, k;
    char *doubled = malloc(2 * strlen(output[0]) + 1); // Allocate memory for doubled

    if (doubled == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (j = 1; j < 500; j++) {
        strcpy(doubled, output[j]);
        strcat(doubled, output[j]);

        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                output[j] = doubled; // This assignment might need reconsideration
            }

            if (strcmp(output[k], doubled) == 0) {
                free(output[j]); // Free memory before setting to NULL
                output[j] = NULL;
                break; // Exit loop if found duplicate
            }
        }
    }

    free(doubled); // Free memory allocated for doubled
    return 0;
}
