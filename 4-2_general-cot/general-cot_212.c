#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i, j;
    char* temp;
    char** names;
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
        // Clear the input buffer
        if (names[i][strlen(names[i]) - 1] == '\n') {
            names[i][strlen(names[i]) - 1] = '\0';
        }
    }

    // Sorting the names
    for (i = 0; i < amount; i++)
    {
        for (j = i + 1; j < amount; j++)
        {
            if (strcmp(names[j], names[i]) < 0)
            {
                temp = names[j];
                names[j] = names[i];
                names[i] = temp;
            }
        }
    }

    // Reallocating the space for each name to exact size
    for (i = 0; i < amount; i++)
    {
        int len = strlen(names[i]);
        names[i] = (char*)realloc(names[i], (len + 1) * sizeof(char));
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
