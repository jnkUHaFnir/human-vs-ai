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

    printf("Enter names and ages (type 'stop' to stop):\n");

    while (1)
    {
        // Reallocate memory to store one more person
        Ptr = (struct info *)realloc(Ptr, (i + 1) * sizeof(struct info));

        printf("Enter name and age for person %d:\n", i + 1);
        scanf("%s", (Ptr + i)->name);

        // Check if the input is "stop"
        if (strcmp((Ptr + i)->name, "stop") == 0)
        {
            break;
        }

        scanf("%d", &(Ptr + i)->age);
        i++;
    }

    // Save the number of people
    int num = i;

    printf("\nList of people:\n");
    for (i = 0; i < num; ++i)
    {
        printf("Name = %s, Age = %d\n", (Ptr + i)->name, (Ptr + i)->age);
    }

    // Free the allocated memory
    free(Ptr);

    return 0;
}
