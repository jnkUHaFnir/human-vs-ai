#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    int num_strings = 5; // Example: Number of strings
    char **array_of_strings;

    // Allocate memory for array of strings
    array_of_strings = (char **)malloc(num_strings * sizeof(char *));

    if (array_of_strings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each string
    for (int i = 0; i < num_strings; i++) {
        array_of_strings[i] = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));
        if (array_of_strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d.\n", i+1);

            // Free memory allocated so far before exiting
            for (int j = 0; j < i; j++) {
                free(array_of_strings[j]);
            }
            free(array_of_strings);
            return 1;
        }
    }

    // Use the array_of_strings here

    // Free allocated memory
    for (int i = 0; i < num_strings; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
