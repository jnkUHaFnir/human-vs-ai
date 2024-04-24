#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;
    size_t total_length = 0;

    // Calculate total length needed for the final string
    for (i = 0; i < number_of_chunks; i++)
    {
        char *chunk = some_hash_table.pop(i);
        total_length += strlen(chunk);
    }

    // Allocate memory for the final string
    final_string = (char *)malloc(total_length + 1); // +1 for the null terminator
    if (final_string == NULL)
    {
        // Handle allocation failure
        return 1;
    }
    
    final_string[0] = '\0'; // Ensure final string is initially empty
    
    // Concatenate chunks into the final string
    for (i = 0; i < number_of_chunks; i++)
    {
        char *chunk = some_hash_table.pop(i);
        strcat(final_string, chunk);
    }

    // Use the final_string as needed

    // Free the allocated memory after use
    free(final_string);

    return 0;
}
