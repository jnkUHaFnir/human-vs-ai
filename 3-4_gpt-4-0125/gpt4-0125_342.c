#include <stdio.h>
#include <stdlib.h> // For free()

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;

    for(i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = "some_chunk_data"; // Assume this comes from some_hash_table.pop(i)
        char *new_str = NULL;
        if (asprintf(&new_str, "%s%s", (final_string==NULL ? "" : final_string), chunk) == -1) {
            // Handle error: asprintf failed to allocate memory
            break;
        }
        free(final_string); // Free the previous final_string
        final_string = new_str; // Update final_string to point to the new block
    }
    printf("%s\n", final_string); // Do something with final_string

    // Cleanup before exiting
    free(final_string);
    return 0;
}
