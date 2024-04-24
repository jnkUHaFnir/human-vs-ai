#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t message_len = 1; /* + 1 for terminating NULL */
    char *buffer = (char*) malloc(message_len);
    
    if (buffer == NULL) {
        printf("Memory allocation failed.");
        return -1;
    }
    
    buffer[0] = '\0'; // Initialize buffer with null terminator
    
    for (int i = 0; i < 200000; i++) {
        // Calculate the size needed for the new string
        int size = snprintf(NULL, 0, "%d \n", i);
        
        // Allocate memory for the new string
        char* a = (char*) malloc(size + 1); // +1 for null terminator
        
        // Construct the new string
        sprintf(a, "%d \n", i);
        
        // Reallocate memory for the buffer to accommodate the new string
        message_len += size;
        buffer = (char*) realloc(buffer, message_len + 1); // +1 for null terminator
        
        // Concatenate the new string to the buffer
        strcat(buffer, a);
        
        // Free the memory allocated for the temporary string
        free(a);
    }
    
    // Print a substring of the final buffer
    char substr[56];
    memcpy(substr, buffer, 55);
    substr[55] = '\0'; // Add null terminator to the substring
    
    printf("%s", substr);
    
    // Free the memory allocated for the buffer
    free(buffer);
    
    return 0;
}
