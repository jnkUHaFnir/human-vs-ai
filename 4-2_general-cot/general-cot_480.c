#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strcpy function

struct info
{
    int age;
    char name[30];
};

int main()
{
    struct info *Ptr = NULL; // Initialize to NULL
    int i = 0;
    int capacity = 1; // Initial capacity
  
    char stop[5] = "stop";
    char input[5];

    while(1)
    {
        // Allocate memory for new entry
        struct info *temp = realloc(Ptr, capacity * sizeof(struct info));
        if (temp == NULL)
        {
            printf("Memory allocation failed. Exiting...");
            break;
        }
        else
        {
            Ptr = temp;
        }

        printf("Enter name and age (or 'stop' to exit):\n");
        scanf("%s", input);
      
        if (strcmp(input, stop) == 0)
        {
            break; // Exit loop if 'stop' entered
        }
      
        strcpy((Ptr+i)->name, input);      
        scanf("%d", &(Ptr+i)->age);

        capacity++; // Increase capacity for the next iteration
        i++;
    }

    for(int j = 0; j < i ; ++j)
    {
        printf("Name = %s, Age = %d\n", (Ptr+j)->name, (Ptr+j)->age);
    }

    // Free dynamically allocated memory
    free(Ptr);

    return 0;
}
