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
        printf("Enter name and age (or 'stop' to finish):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        // Allocate memory for one more struct info
        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));

        printf("Enter age:\n");
        scanf("%d", &(Ptr+i)->age);

        strcpy((Ptr+i)->name, input);

        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", (Ptr+j)->name, (Ptr+j)->age);
    }

    // Free the allocated memory
    free(Ptr);

    return 0;
}
