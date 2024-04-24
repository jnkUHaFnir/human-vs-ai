#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;

    for(i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = some_hash_table.pop(i);
        size_t old_len = (final_string == NULL) ? 0 : strlen(final_string);
        size_t chunk_len = strlen(chunk);
        
        final_string = (char *)realloc(final_string, old_len + chunk_len + 1); // +1 for the null terminator
        if(final_string == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }

        strcat(final_string, chunk);
    }

    // Use final_string as needed

    free(final_string); // Free the memory once done
    return 0;
}
