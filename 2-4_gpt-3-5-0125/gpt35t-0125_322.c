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
        printf("Enter name and age (Type 'stop' to end):\n");
        scanf("%s", input);
        
        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        Ptr = (struct info *)realloc(Ptr, (i + 1) * sizeof(struct info));

        if (Ptr == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        strcpy((Ptr + i)->name, input);
        scanf("%d", &(Ptr + i)->age);

        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", (Ptr + j)->name, (Ptr + j)->age);
    }

    free(Ptr);

    return 0;
}
