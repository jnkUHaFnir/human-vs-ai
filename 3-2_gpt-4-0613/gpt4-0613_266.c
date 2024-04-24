#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char** t;
    t = (char**)malloc(16 * sizeof(char*));
    if (t == NULL){ // Always check the result of malloc
        printf("Memory allocation failed\n");
        return -1;
    }
        
    for(i = 0; i < 16; i++)
    {
        t[i] = (char*)malloc(16*sizeof(char));
        if (t[i] == NULL){ 
            printf("Memory allocation failed\n");
            // If malloc fails, the allocated memory until now needs to be freed
            for(int j = 0; j < i; j++)
                free(t[j]);
            free(t);
            return -1;
        }
    }

    // Always remember to free memory allocated using malloc
    for(i = 0; i < 16; i++)
    {
        free(t[i]);
    }
    free(t);

    return 0;
}
