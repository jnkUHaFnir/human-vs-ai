    #include <stdio.h>
    #include <stdlib.h>
    int main()
    {
        int i;
        int number_of_chunks = 12;
        char *final_string[12];
 
        for(i = 0; i < number_of_chunks; i++)
        {
            char *chunk = some_hash_table.pop(i);
            asprintf(&final_string[i], "%s%s", (final_string==NULL?"":final_string), chunk);
        }
 
        for(i = 0; i < number_of_chunks; i++)
            free(final_string[i]);
        return 0;
    }