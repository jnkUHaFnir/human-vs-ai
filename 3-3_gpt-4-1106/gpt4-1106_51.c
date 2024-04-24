#include <stdio.h>
#include <stdlib.h>

int main() {
    char* buffer = NULL;
    int buffer_size = 0;
    int buffer_capacity = 0;
    char c;

    printf("Enter the address of the employee (End with Ctrl+D): \n");
    
    while ((c = getchar()) != EOF) {
        // Check if we need to expand our buffer
        if (buffer_size + 1 > buffer_capacity) {
            buffer_capacity = buffer_capacity == 0 ? 1 : buffer_capacity * 2;
            char* new_buffer = realloc(buffer, buffer_capacity);
            if (!new_buffer) {
                free(buffer);
                fprintf(stderr, "Failed to allocate memory\n");
                return 1;
            }
            buffer = new_buffer;
        }

        // Add the character to the buffer
        buffer[buffer_size] = c;
        buffer_size++;
    }

    // Null-terminate the string
    if (buffer_capacity == buffer_size) {
        // Ensure there's room for the null terminator
        char* new_buffer = realloc(buffer, buffer_size + 1);
        if (!new_buffer) {
            free(buffer);
            fprintf(stderr, "Failed to allocate memory for null terminator\n");
            return 1;
        }
        buffer = new_buffer;
    }
    buffer[buffer_size] = '\0';

    printf("\nEmployee's Address:\n%s\n", buffer);

    // Free the buffer at the end
    free(buffer);

    return 0;
}
