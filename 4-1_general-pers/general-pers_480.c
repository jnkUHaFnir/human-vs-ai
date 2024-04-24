#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

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

    while(1)
    {
        printf("Enter name and age (or type 'stop' to finish):\n");
        scanf("%s", input);

        if(strcmp(input, "stop") == 0)
        {
            break;
        }

        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info)); // Dynamically allocate memory
        
        if(Ptr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        strcpy(Ptr[i].name, input); // Copy the name
        scanf("%d", &Ptr[i].age); // Input the age

        i++;
    }

    for(int j = 0; j < i; j++)
    {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    free(Ptr); // Free the allocated memory

    return 0;
}
