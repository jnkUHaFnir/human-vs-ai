#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of input buffer

int main() {
    char *input = NULL;
    size_t len = 0;

    printf("Enter a string: ");
    input = malloc(MAX_SIZE * sizeof(char)); // Allocate memory for input

    if (input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (fgets(input, MAX_SIZE, stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Now you can use the input string as needed
    printf("You entered: %s\n", input);

    // Don't forget to free the allocated memory
    free(input);

    return 0;
}
