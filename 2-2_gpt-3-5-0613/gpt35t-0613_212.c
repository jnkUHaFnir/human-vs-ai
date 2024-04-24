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
        names[i][strcspn(names[i], "\n")] = '\0'; // remove trailing newline character
    }

    // Sorting the names using bubble sort
    for (i = 0; i < amount-1; i++)
    {
        for (j = 0; j < amount-i-1; j++)
        {
            if (strcmp(names[j], names[j+1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }

    // Reallocating the space needed for each name
    for (i = 0; i < amount; i++)
    {
        int length = strlen(names[i]);
        names[i] = (char*)realloc(names[i], (length + 1) * sizeof(char));
    }

    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
    }

    // Freeing the memory
    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);
    free(temp);

    getchar();
    return 0;
}
