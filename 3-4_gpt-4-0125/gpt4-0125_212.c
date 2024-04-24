#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i = 0, j = 0;
    char** names = NULL;
    int amount = 0;

    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar(); // To catch the newline.

    names = (char**)malloc(amount * sizeof(char*));

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_CHARS + 1) * sizeof(char));
    }

    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_CHARS, stdin);

        // Removing trailing newline character.
        names[i][strcspn(names[i], "\n")] = 0;
    }

    // Sorting the names.
    for (i = 0; i < amount; i++)
    {
        for (j = i + 1; j < amount; j++)
        {
            if (strcmp(names[j], names[i]) < 0)
            {
                // Swapping pointers
                char* temp = names[j];
                names[j] = names[i];
                names[i] = temp;
            }
        }

        // Reallocating to fit exactly the space needed.
        names[i] = (char*)realloc(names[i], strlen(names[i]) + 1); // +1 for the null terminator.
    }

    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
    }

    // Freeing the allocated space
    for (i = 0; i < amount; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}
