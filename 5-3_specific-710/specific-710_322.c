#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (i % 2 == 0) // Double the memory allocation every 2 iterations
        {
            Ptr = (struct info *)realloc(Ptr, (i + 2) * sizeof(struct info));
            if (Ptr == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }
        }

        printf("Enter name and age (or 'stop' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        strcpy((Ptr + i)->name, input);
        scanf("%d", &(Ptr + i)->age);
        i++;
    }

    for (int j = 0; j < i; ++j)
    {
        printf("Name = %s, Age = %d\n", (Ptr + j)->name, (Ptr + j)->age);
    }

    free(Ptr); // Free the allocated memory

    return 0;
}
