#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int total_length = 0;
    int number_of_chunks = 12;
    char *final_string = NULL;
    char *chunk;
    
    // Calculate the total length of all chunks
    for(i = 0; i < number_of_chunks; i++)
    {
        chunk = some_hash_table.pop(i);
        total_length += strlen(chunk);
    }

    // Allocate memory for the final concatenated string
    final_string = (char*)malloc(total_length + 1); // +1 for the null terminator
    final_string[0] = '\0'; // Initialize final_string as an empty string

    // Concatenate the chunks into final_string
    for(i = 0; i < number_of_chunks; i++)
    {
        chunk = some_hash_table.pop(i);
        strcat(final_string, chunk);
    }
    
    // Use final_string as needed

    // Don't forget to free the allocated memory when done
    free(final_string);

    return 0;
}
