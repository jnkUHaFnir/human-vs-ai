#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = malloc(number_of_chunks * MAX_CHUNK_SIZE * sizeof(char));
    
    int total_length = 0;

    for(i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = some_hash_table.pop(i);
        int chunk_length = strlen(chunk);
        
        memcpy(final_string + total_length, chunk, chunk_length);
        total_length += chunk_length;
    }
    
    final_string[total_length] = '\0';
    
    // Do something with the final concatenated string
    
    free(final_string);
    return 0;
}
