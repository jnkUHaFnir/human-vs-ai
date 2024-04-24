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
    char input[20];

    while (1)
    {
        printf("Enter name and age (enter 'stop' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        // Reallocate memory for one more struct
        Ptr = (struct info *)realloc(Ptr, (i + 1) * sizeof(struct info));

        printf("Enter age:\n");
        scanf("%d", &(Ptr + i)->age);

        strcpy((Ptr + i)->name, input);

        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", (Ptr + j)->name, (Ptr + j)->age);
    }

    free(Ptr); // Free the allocated memory

    return 0;
}
