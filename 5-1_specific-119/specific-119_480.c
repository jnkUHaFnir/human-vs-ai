#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string comparison

struct info
{
    int age;
    char name[30];
};

int main()
{
    struct info *Ptr = NULL;
    int i = 0;
    char input[30];

    while (1)
    {
        printf("Enter name and age (or 'stop' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break; // Exit the loop if the user enters "stop"
        }

        // Dynamically allocate more memory for each new entry
        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));

        if (Ptr == NULL)
        {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }

        printf("Enter age: ");
        scanf("%d", &(Ptr + i)->age);

        // Consume the remaining newline character in the input buffer
        getchar();

        printf("Enter name: ");
        fgets((Ptr + i)->name, 30, stdin);
        // Remove the newline character at the end of the name
        (Ptr + i)->name[strcspn((Ptr + i)->name, "\n")] = '\0';

        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", (Ptr + j)->name, (Ptr + j)->age);
    }

    // Free the dynamically allocated memory before exiting the program
    free(Ptr);

    return 0;
}
