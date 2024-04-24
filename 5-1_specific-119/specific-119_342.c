#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int number_of_chunks = 12;
    size_t total_length = 1; // Initialize with 1 to hold the null terminator

    char *final_string = (char*)malloc(total_length);

    if(final_string == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    final_string[0] = '\0'; // Initialize final_string as an empty string

    for(i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        size_t chunk_length = strlen(chunk);

        // Expand the buffer to accommodate the new chunk
        total_length += chunk_length;
        final_string = (char*)realloc(final_string, total_length);

        if(final_string == NULL) {
            perror("Memory reallocation failed");
            return 1;
        }

        strcat(final_string, chunk);
    }

    // Use final_string

    free(final_string);

    return 0;
}
