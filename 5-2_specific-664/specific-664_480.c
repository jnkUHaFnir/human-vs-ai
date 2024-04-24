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
        struct info *tempPtr = realloc(Ptr, (i + 1) * sizeof(struct info));
        if (tempPtr == NULL)
        {
            // Handle allocation failure
            printf("Memory allocation failed.\n");
            break;
        }
        Ptr = tempPtr;

        printf("Enter name and age (or 'stop' to exit):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0)
        {
            break;
        }
        
        // Copy name from input to struct
        strncpy(Ptr[i].name, input, sizeof(Ptr[i].name) - 1);
        Ptr[i].name[sizeof(Ptr[i].name) - 1] = '\0'; // Ensure null-termination

        scanf("%d", &(Ptr[i].age));

        i++;
    }

    for(int j = 0; j < i; ++j)
    {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    free(Ptr); // Free the allocated memory

    return 0;
}
