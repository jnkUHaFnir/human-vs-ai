#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Example, you want an array for 10 strings
    char** arrayOfStrings;

    // Allocate memory for 'x' pointers to strings
    arrayOfStrings = malloc(x * sizeof(char*));
    if (arrayOfStrings == NULL) {
        // Always check if malloc was successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Now allocate memory for each string
    for (int i = 0; i < x; i++) {
        arrayOfStrings[i] = malloc(50 * sizeof(char)); // 50 bytes for each string
        if (arrayOfStrings[i] == NULL) {
            // Check each allocation
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            exit(1);
        }
    }

    // Remember to free the allocated memory once done
    // First free each string
    for (int i = 0; i < x; i++) {
        free(arrayOfStrings[i]);
    }
    // Then free the array of pointers itself
    free(arrayOfStrings);

    return 0;
}
arrayOfStrings[i] = calloc(50, sizeof(char)); // Allocates and zeroes out the space
