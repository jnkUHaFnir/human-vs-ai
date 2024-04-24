#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024 // Chunk size for dynamic reallocation

int main() {
    size_t buffer_size = CHUNK_SIZE; // Initial buffer size
    char *buffer = malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed");
        return -1;
    }

    buffer[0] = '\0'; // Initialize buffer with null terminator

    for (int i = 0; i < 200000; i++) {
        // Calculate the size needed for the new string
        int size = snprintf(NULL, 0, "%d \n", i);

        // Check if reallocation is needed
        if (buffer_size < size + strlen(buffer) + 1) {
            buffer_size += CHUNK_SIZE;
            char *temp = realloc(buffer, buffer_size * sizeof(char));
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed");
                free(buffer);
                return -1;
            }
            buffer = temp;
        }

        // Append the new string to the buffer
        sprintf(buffer + strlen(buffer), "%d \n", i);
    }

    // Example of using the built string
    char substr[56];
    memcpy(substr, buffer, 55);
    substr[55] = '\0'; // Ensure null-terminated
    printf("%s", substr);

    // Clean up
    free(buffer);

    return 0;
}
