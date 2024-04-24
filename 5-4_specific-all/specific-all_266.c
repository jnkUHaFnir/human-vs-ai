#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc function

int main() {
    int i;
    char** t;

    // Allocate memory for 16 char pointers
    t = (char**)malloc(16 * sizeof(char*));

    // Check if memory allocation was successful
    if (t == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 16; i++) {
        // Allocate memory for each individual string
        t[i] = (char*)malloc(16 * sizeof(char));

        // Check if memory allocation was successful
        if (t[i] == NULL) {
            printf("Memory allocation failed for string %d\n", i);
            return 1;
        }
    }

    // Free the allocated memory when done
    for (i = 0; i < 16; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}
