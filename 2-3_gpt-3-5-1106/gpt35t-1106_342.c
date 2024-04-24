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
        size_t current_length = (final_string == NULL) ? 0 : strlen(final_string);
        size_t new_length = current_length + strlen(chunk) + 1; // +1 for the null terminator

        final_string = (char *)realloc(final_string, new_length);
        if (final_string == NULL) {
            // handle memory allocation error
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }

        strcat(final_string, chunk);
    }

    // do something with final_string

    free(final_string);
    return 0;
}
