#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // You can change this to whatever maximum you expect or can handle

int main() {
    char buffer[MAX_LINE_LENGTH]; // Allocate a buffer on the stack
    
    // Read lines from stdin until EOF is reached.
    while (fgets(buffer, MAX_LINE_LENGTH, stdin)) {
        // Note that fgets() stores the newline character (\n) in the buffer
        // Remove the newline character if you don't want it
        buffer[strcspn(buffer, "\n")] = 0;

        // Do something with the input string buffer
        printf("You entered: %s\n", buffer);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t buffer_size = 32; // Initial size of the buffer
    char *buffer = malloc(buffer_size * sizeof(char)); // Allocate initial buffer
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Enter a line: ");

    size_t current_size = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // If the buffer is full, expand it
        if (current_size == buffer_size - 1) {
            buffer_size *= 2; // Double the buffer size
            char *new_buffer = realloc(buffer, buffer_size * sizeof(char));
            if (new_buffer == NULL) {
                perror("Unable to reallocate buffer");
                free(buffer);
                exit(1);
            }
            buffer = new_buffer;
        }

        // Append the character to the buffer
        buffer[current_size++] = (char)c;
    }

    // Null-terminate the string
    buffer[current_size] = '\0';

    // Do something with the input string buffer
    printf("You entered: %s\n", buffer);

    // Don't forget to free the buffer when you're done with it
    free(buffer);

    return 0;
}
