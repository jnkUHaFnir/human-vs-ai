#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i, j;
    char temp[MAX_CHARS];
    char** names;
    int amount;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar(); // Consume newline

    // Allocating space for the names.
    names = (char**)malloc(amount * sizeof(char*));
    if (names == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc(MAX_CHARS * sizeof(char));
        if (names[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return -1;
        }
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS, stdin);
        // Remove newline character
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Sorting the names
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
        // Reallocating the names to only the space needed.
        names[i] = (char*)realloc(names[i], strlen(names[i]) + 1);
        if (names[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return -1;
        }
    }

    printf("Sorted names:\n");
    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
    }

    // Free allocated memory
    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}
