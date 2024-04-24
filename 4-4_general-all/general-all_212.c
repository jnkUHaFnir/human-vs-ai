#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

int main(void)
{
    int i, j;
    char temp[MAX_NAME_LENGTH]; // Temporary storage for swapping names during sorting
    char** names = NULL;
    int amount;

    // Getting number of friends from user
    printf("Enter number of friends: ");
    scanf("%d", &amount);
    getchar(); // Consume newline

    // Allocating space for the names.
    names = (char**)malloc(amount * sizeof(char*));

    for (i = 0; i < amount; i++)
    {
        names[i] = (char*)malloc((MAX_NAME_LENGTH + 1) * sizeof(char)); // Allocate space for the name and null terminator
    }

    // Getting the names from the user
    for (i = 0; i < amount; i++)
    {
        printf("Enter name of friend %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin); 
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove trailing newline character
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
        // Reallocating the memory to fit the exact size of the name
        names[i] = (char*)realloc(names[i], (strlen(names[i]) + 1) * sizeof(char)); // Add space for the null terminator
    }

    // Printing the sorted names
    for (i = 0; i < amount; i++)
    {
        printf("%s\n", names[i]);
        free(names[i]); // Free individual names
    }

    free(names); // Free the array of names
    return 0;
}
