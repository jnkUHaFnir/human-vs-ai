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

    printf("Enter name and age for each person. Type 'stop' for name to exit.\n");

    while (1)
    {
        // Dynamically allocate memory for the new person
        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));

        printf("Enter name for person %d: ", i + 1);
        scanf("%s", Ptr[i].name);

        if (strcmp(Ptr[i].name, "stop") == 0)
            break;
        
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &Ptr[i].age);

        i++;
    }

    printf("\nEntered information for each person:\n");
    for (int j = 0; j < i; ++j)
        printf("Person %d - Name: %s, Age: %d\n", j + 1, Ptr[j].name, Ptr[j].age);

    // Free the allocated memory before exiting
    free(Ptr);

    return 0;
}
