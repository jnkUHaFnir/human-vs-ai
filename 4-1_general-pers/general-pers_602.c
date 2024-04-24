#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string functions

#define SIZE 100

int main(void) {
    char* username[SIZE]; // Array to hold pointers to words
    int i;

    /* Read words into array */
    for (i = 0; i < SIZE; i++) {
        username[i] = (char*)malloc(SIZE * sizeof(char)); // Allocate memory for each word

        if (username[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1); // Exit program if memory allocation fails
        }

        if (scanf("%99s", username[i]) != 1) { // Read up to 99 characters to avoid buffer overflow
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }
    }

    /* Print out array */
    for (i = 0; i < SIZE; i++) {
        if (username[i][0] != '\0') { // Check if the word is not an empty string
            printf("%s\n", username[i]);
        }
    }

    /* Free allocated memory */
    for (i = 0; i < SIZE; i++) {
        free(username[i]);
    }

    return 0;
}
