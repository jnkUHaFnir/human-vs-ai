#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize total message length and initial buffer size
    size_t message_len = 1; /* + 1 for terminating NULL */
    size_t buffer_size = 1024; // starting buffer size

    // Allocate memory for the initial buffer
    char *buffer = (char*)malloc(buffer_size);
    buffer[0] = '\0'; // Ensure the buffer is null-terminated

    for (int i = 0; i < 200000; i++) {
        int size = snprintf(NULL, 0, "%d \n", i);

        // Allocate memory for the new string and format it
        char *a = (char*)malloc(size + 1);
        sprintf(a, "%d \n", i);
        
        // Check if there is enough space in the buffer, if not, expand it
        if (message_len + size + 1 > buffer_size) {
            buffer_size *= 2; // Double the buffer size
            buffer = (char*)realloc(buffer, buffer_size);
        }

        // Concatenate the new string to the buffer
        strcat(buffer, a);
        
        // Update the total message length
        message_len += size;
        
        // Free the memory allocated for 'a'
        free(a);
    }

    // Use the final large string as needed
    printf("%.56s\n", buffer); // Print only the first 56 characters

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}
