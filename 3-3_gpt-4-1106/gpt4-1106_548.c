#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    char *directions[3];
    int i;

    // Allocate memory for each string
    for(i = 0; i < 3; i++) {
        directions[i] = malloc(100 * sizeof(char)); // Allocate memory for a string of 99 characters + null terminator
        if (directions[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for directions[%d]\n", i);
            // Handle the memory allocation failure by exiting or freeing any previously allocated memory
            exit(EXIT_FAILURE);
        }
    }

    // Read strings into the allocated memory
    for(i = 0; i < 3; i++) {
        printf("Enter direction %d: ", i+1);
        scanf("%99s", directions[i]); // Limit input to 99 characters to avoid buffer overflow
    }

    // Print out the strings
    for(i = 0; i < 3; i++) {
        printf("Direction %d: %s\n", i+1, directions[i]);
    }

    // Free the allocated memory
    for(i = 0; i < 3; i++) {
        free(directions[i]);
    }

    return 0;
}
