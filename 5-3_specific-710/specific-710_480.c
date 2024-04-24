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

    printf("Enter name and age (or 'stop' to exit):\n");

    while(1)
    {
        // Allocate memory for one more struct
        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));
        
        // Obtain input
        scanf("%s", input);

        // Check for exit condition
        if (strcmp(input, "stop") == 0) {
            break;
        }

        // Read age
        scanf("%d", &(Ptr+i)->age);

        // Copy name to struct
        strncpy((Ptr+i)->name, input, sizeof((Ptr+i)->name) - 1);
        (Ptr+i)->name[sizeof((Ptr+i)->name) - 1] = '\0'; // Ensure null-terminated

        i++;
    }

    // Output the stored information
    for(int j = 0; j < i; j++)
        printf("Name = %s, Age = %d\n", (Ptr+j)->name, (Ptr+j)->age);

    // Free the allocated memory
    free(Ptr);

    return 0;
}
