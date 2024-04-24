#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = calloc(1, sizeof(char)); // allocated with 1 size initially

    for(i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = some_hash_table.pop(i);

        // Resize the final_string to accommodate the new chunk
        final_string = realloc(final_string, strlen(final_string) + strlen(chunk) + 1);

        // Concatenate the new chunk
        strcat(final_string, chunk);
    }

    printf("%s\n", final_string);

    free(final_string); // don't forget to free the memory
    return 0;
}
