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

    // Continuously allocate memory one by one until user enters "stop"
    while (1)
    {
        printf("Enter name and age (or 'stop' to end):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break;
        }

        // Reallocate memory for one more struct
        Ptr = (struct info *)realloc(Ptr, (i + 1) * sizeof(struct info));

        printf("Enter age:\n");
        scanf("%d", &Ptr[i].age);

        strncpy(Ptr[i].name, input, sizeof(Ptr[i].name) - 1);
        Ptr[i].name[sizeof(Ptr[i].name) - 1] = '\0';

        i++;
    }

    // Output the collected information
    for (int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    // Free allocated memory
    free(Ptr);

    return 0;
}
