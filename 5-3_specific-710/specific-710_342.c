#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;
    size_t total_length = 0;

    // Calculate total length to allocate memory once
    for(i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        total_length += strlen(chunk);
    }

    // Allocate memory for the final string
    final_string = (char*)malloc(total_length + 1); // +1 for null terminator
    
    // Concatenate chunks into final_string
    final_string[0] = '\0'; // Ensure final_string is an empty string
    for(i = 0; i < number_of_chunks; i++) {
        char *chunk = some_hash_table.pop(i);
        strcat(final_string, chunk);
    }

    // Use final_string as needed
    
    // Clean up
    free(final_string);
    
    return 0;
}
