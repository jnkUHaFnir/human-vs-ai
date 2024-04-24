#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 1024

int main() {
    size_t message_len = INITIAL_BUFFER_SIZE;
    char *buffer = (char*) malloc(message_len);
    buffer[0] = '\0'; // Initialize the buffer as an empty string

    for (int i = 0; i < 200000; i++) {
        int size = snprintf(NULL, 0, "%d \n", i) + 1; // +1 for the null terminator
        char *a = (char*) malloc(size);
        sprintf(a, "%d \n", i);

        if (message_len < strlen(buffer) + size) {
            message_len *= 2; // Double the buffer size if needed
            buffer = (char*) realloc(buffer, message_len);
        }

        strcat(buffer, a);

        free(a); // Free the temporary string
    }

    // Use the string buffer as needed
    char substr[56];
    memcpy(substr, buffer, 56);
    substr[56] = '\0'; // Ensure null-termination for printing substr

    printf("%s", substr);

    // Don't forget to free the buffer when done
    free(buffer);

    return 0;
}
