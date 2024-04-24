#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

int main(void)
{
    int i, j, amount;
    char temp[MAX_CHARS + 1];
    char** names = NULL;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar(); // to clear the newline character left by scanf

    // Allocating space for the names
    names = (char**)malloc(amount * sizeof(char*));
    if (names == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc(MAX_CHARS + 1);
        if (names[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        if (fgets(names[i], MAX_CHARS + 1, stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            return 1;
        }
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline character at the end
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
    }

    // Reallocating the space to fit the exact length of the string
    for (i = 0; i < amount; i++)
    {
        size_t length = strlen(names[i]) + 1;
        char* tmp = (char*)realloc(names[i], length);
        if (tmp == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            return 1;
        }
        names[i] = tmp;
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
