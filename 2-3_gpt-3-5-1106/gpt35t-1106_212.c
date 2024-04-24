#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i, j;
    char** names = NULL;
    int amount;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar();

    // Allocating space for the names.
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
        names[i][strcspn(names[i], "\n")] = 0;  // Removing the newline character
        names[i] = (char*)realloc(names[i], strlen(names[i]) + 1);  // Reallocating the space based on the length of the string
    }

    // Sorting the names
    for (i = 0; i < amount; i++)
    {
        for (j = 0; j < amount - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char* temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    // Printing the sorted names
    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
    }

    // Freeing memory
    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}
