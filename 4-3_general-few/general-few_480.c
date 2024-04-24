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
    char stop[5];

    // Initially allocate memory for 1 struct
    Ptr = (struct info*)malloc(sizeof(struct info));

    while (1)
    {
        printf("Enter name and age (or 'stop' to finish):\n");
        scanf("%s", stop);

        if (strcmp(stop, "stop") == 0)
        {
            break;
        }

        if (i > 0)
        {
            // Reallocate memory for additional struct
            Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));
        }

        printf("Enter age:\n");
        scanf("%d", &(Ptr[i].age));
        printf("Enter name:\n");
        scanf("%s", Ptr[i].name);

        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    // Free the dynamically allocated memory
    free(Ptr);

    return 0;
}
