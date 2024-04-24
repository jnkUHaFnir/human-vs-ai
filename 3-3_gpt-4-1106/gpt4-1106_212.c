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
    getchar(); // Eat the newline

    // Allocating space for the array of strings
    names = (char**)malloc(amount * sizeof(char*));

    // Allocating space for the buffer used for sorting
    temp = (char*)malloc((MAX_CHARS + 1) * sizeof(char));

    // Allocate space for the names and initialize them
    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_CHARS + 1) * sizeof(char));
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS, stdin);
        // Stripping newline character
        names[i][strcspn(names[i], "\n")] = 0;
    }

    // Sorting the names
    for (i = 0; i < amount; i++)
    {
        for (j = i + 1; j < amount; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Free the temporary buffer, it won't be needed anymore
    free(temp);

    // Reallocating the 50 bytes space to only the space needed
    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)realloc(names[i], strlen(names[i]) + 1);
    }

    // Print the names after sorting and reallocating space
    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
        free(names[i]); // Free individual strings
    }

    free(names); // Free the array of strings
    return 0;
}
