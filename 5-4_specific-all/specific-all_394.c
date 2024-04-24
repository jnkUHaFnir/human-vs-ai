#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t message_len = 1;
    char *buffer = (char*) malloc(message_len);
    
    if (buffer == NULL) {
        return -1; // Error handling for malloc failure
    }
    
    buffer[0] = '\0'; // Null-terminate the empty buffer
    
    for (int i = 0; i < 200000; i++) {
        int size = snprintf(NULL, 0, "%d \n", i);
        char *a = malloc(size + 1);
        
        if (a == NULL) {
            return -1; // Error handling for malloc failure
        }
        
        sprintf(a, "%d \n", i);

        // Resize buffer to accommodate new string
        message_len += strlen(a);
        buffer = (char*) realloc(buffer, message_len);
        
        if (buffer == NULL) {
            return -1; // Error handling for realloc failure
        }
        
        strcat(buffer, a);

        free(a);
    }
    
    char substr[56];
    memcpy(substr, buffer, 56);
    substr[56] = '\0'; // Null-terminate substr just in case buffer is smaller than 56
    
    printf("%s", substr);
    
    // Don't forget to free the allocated memory
    free(buffer);
    
    return 0;
}
