#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Suppose we want an array for 10 strings
    int maxStringLength = 50;

    // Allocate the memory for the array of strings
    char **arrayOfStrings = (char **)malloc(x * sizeof(char *));
    if (arrayOfStrings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Now allocate memory for each string
    for (int i = 0; i < x; i++) {
        arrayOfStrings[i] = (char *)malloc((maxStringLength + 1) * sizeof(char));
        if (arrayOfStrings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            
            // Clean up previously allocated string memory
            for (int j = 0; j < i; j++) {
                free(arrayOfStrings[j]);
            }
            // Free the array of pointers
            free(arrayOfStrings);
            return 1;
        }
    }

    // Remember to free the memory later when you're done with it
    for (int i = 0; i < x; i++) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Suppose we want an array for 10 strings
    int maxStringLength = 50;

    // Allocate memory for the array of string pointers
    char **arrayOfStrings = (char **)calloc(x, sizeof(char *));
    if (arrayOfStrings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each string
    for (int i = 0; i < x; i++) {
        arrayOfStrings[i] = (char *)calloc(maxStringLength + 1, sizeof(char));
        if (arrayOfStrings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            
            // Clean up previously allocated string memory
            for (int j = 0; j < i; j++) {
                free(arrayOfStrings[j]);
            }
            // Free the array of pointers
            free(arrayOfStrings);
            return 1;
        }
    }

    // Remember to free the memory later when you're done
    for (int i = 0; i < x; i++) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);

    return 0;
}
