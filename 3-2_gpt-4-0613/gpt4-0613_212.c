#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i = 0, j = 0;
    char* temp = 0;
    char** names = 0;
    int amount = 0;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar();

    // Allocating space for the names.
    temp = (char*)malloc(MAX_CHARS * sizeof(char));
    names = (char**)malloc(amount * sizeof(char*));  // This line was corrected

    if (!temp || !names) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_CHARS + 1) * sizeof(char));
        if (!names[i]) 
        {
            printf("Memory allocation failed for names[%d]\n", i);
            return 1;
        }
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS - 1, stdin);
        
        // replace newline character with null terminator
        names[i][strcspn(names[i], "\n")] = 0;
    }

    // sorting the names string.
    for(i = 0; i < amount-1; i++)
    {
        for(j = i+1; j < amount; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    for (i = 0; i < amount; i++)
    {
        // Reallocating the 50 bytes space to only the space needed.
        printf("%ld\n", strlen(names[i]));  // length of string before reallocation
        names[i] = (char*)realloc(names[i], strlen(names[i]) * sizeof(char) + 1);
        printf("%ld\n", strlen(names[i]));  // length of string after reallocation
    }

    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
        
        // don't forget to free each name before freeing names.
        free(names[i]);
    }

    free(names);
    return 0;
}
