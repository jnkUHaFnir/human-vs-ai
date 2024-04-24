#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i = 0, j = 0;
    char* temp = NULL;
    char** names = NULL;
    int amount = 0;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar();

    // Allocating space for the names
    temp = (char*)malloc(MAX_CHARS * sizeof(char));
    names = (char**)malloc(amount * sizeof(char*));

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_CHARS + 1) * sizeof(char));
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS, stdin);
    }

    for (i = 0; i < amount; i++)
    {
        for (j = i + 1; j < amount; j++)
        {
            if (strcmp(names[j], names[i]) < 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], temp);
            }
        }
        // Reallocating the space to only the space needed.
        names[i] = (char*)realloc(names[i], (strlen(names[i]) + 1) * sizeof(char));
    }

    for (i = 0; i < amount; i++)
    {
        printf("%s", names[i]);
    }

    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);
    
    getchar();
    return 0;
}
