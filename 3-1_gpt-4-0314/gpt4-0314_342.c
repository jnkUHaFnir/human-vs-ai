#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int number_of_chunks = 12;
    char *final_string = NULL;
    size_t final_string_size = 0;

    for(i = 0; i < number_of_chunks; i++) 
    {
        char *chunk = some_hash_table.pop(i);
        size_t new_size = final_string_size + strlen(chunk) + 1;
        final_string = realloc(final_string, new_size);
        
        if(final_string == NULL) 
        {
            printf("Memory allocation error!\n");
            return 1;
        }
        
        if(final_string_size == 0)
        {
            strcpy(final_string, chunk);
        }
        else
        {
            strcat(final_string, chunk);
        }
        
        final_string_size = new_size;
    }
    
    printf("Final string: %s\n", final_string);
    free(final_string);
    return 0;
}
