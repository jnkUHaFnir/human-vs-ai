#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t message_len = 1; // + 1 for terminating NULL
    char *buffer = (char*)malloc(message_len);
    
    for (int i = 0; i < 200000; i++) {
        int size = snprintf(NULL, 0, "%d \n", i);
        
        char* temp_buffer = (char*)malloc(size + 1);
        if(temp_buffer == NULL) {
            // Handle memory allocation error
            return -1;
        }
        
        size = snprintf(temp_buffer, size + 1, "%d \n", i);

        char* new_buffer = (char*)realloc(buffer, message_len + size);
        if(new_buffer == NULL) {
            // Handle memory reallocation error
            free(temp_buffer);
            return -1;
        }
        
        buffer = new_buffer;
        memcpy(buffer + message_len - 1, temp_buffer, size + 1); // Copy formatted string to buffer
        message_len += size; // Update total message length
        free(temp_buffer);
    }

    // Use the complete buffer here

    free(buffer);
    
    return 0;
}
