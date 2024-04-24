#include <stdio.h>
#include <stdlib.h>

int main() {
    char* input = NULL; // Pointer to store the characters
    int counter = 0;
    int buffer_size = 1; // Initial buffer size

    while (1) {
        char c = getchar(); // Read one character at a time

        if (c == '\n') {
            break; // Stop reading when newline character is encountered
        }

        // Allocate memory for the new character
        char* temp = realloc(input, buffer_size * sizeof(char));

        if (temp == NULL) {
            // Error handling for memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            if (input) free(input); // Free the previously allocated memory
            return 1;
        }

        input = temp;
        input[counter++] = c;
        buffer_size++; // Increase buffer size for the next character
    }

    input[counter] = '\0'; // Null-terminate the string

    printf("String: %s\n", input);
    printf("Length of string: %d\n", counter);

    free(input); // Free the allocated memory

    return 0;
}
