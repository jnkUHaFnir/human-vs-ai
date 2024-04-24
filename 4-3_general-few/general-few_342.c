#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;
    size_t final_length = 0;

    for (i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = some_hash_table.pop(i);
        size_t chunk_length = strlen(chunk);

        // Reallocate final_string to accommodate the new chunk
        final_string = (char *)realloc(final_string, final_length + chunk_length + 1);

        if (final_string == NULL)
        {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Copy the chunk to the end of final_string
        strcpy(final_string + final_length, chunk);
        
        // Update final_length
        final_length += chunk_length;
    }

    // Null-terminate the final string
    final_string[final_length] = '\0';

    // Use final_string as needed

    // Don't forget to free the allocated memory
    free(final_string);

    return 0;
}
