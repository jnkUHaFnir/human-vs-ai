#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;
    size_t buffer_size = 0;
    
    for (i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        size_t chunk_size = strlen(chunk);
        
        // Resize the buffer to accommodate the new chunk
        final_string = realloc(final_string, buffer_size + chunk_size + 1);
        if (final_string == NULL) {
            // Handle allocation error
            printf("Memory allocation error");
            free(final_string);
            return 1;
        }
        
        // Append the chunk to the final string
        memcpy(final_string + buffer_size, chunk, chunk_size);
        buffer_size += chunk_size;
        
        // Null-terminate the final string
        final_string[buffer_size] = '\0';
    }
    free(final_string);
    return 0;
}
