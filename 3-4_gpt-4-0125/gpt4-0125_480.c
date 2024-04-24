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
    int num = 0;
    char buffer[30];

    while(1)
    {
        printf("Enter 'stop' or name and age:\n");
        scanf("%s", buffer);

        // Check if the input is "stop" to end the loop
        if(strcmp(buffer, "stop") == 0){
            break;
        }

        // Reallocate memory for one more struct info
        struct info *tempPtr = realloc(Ptr, (num + 1) * sizeof(struct info));
        if(tempPtr == NULL)
        {
            // Handle realloc failure
            printf("Failed to allocate memory. Exiting.\n");
            free(Ptr); // Don't forget to free previously allocated memory before exiting.
            return 1;
        }

        Ptr = tempPtr; // Update Ptr with the new memory location returned by realloc
        strcpy(Ptr[num].name, buffer); // Copy the name into the newly allocated struct

        // Read age from input
        scanf("%d", &Ptr[num].age);
        num++; // Increase counter for the number of people
    }

    // Print all names and ages
    for(int i = 0; i < num ; ++i)
        printf("Name = %s, Age = %d\n", Ptr[i].name, Ptr[i].age);

    // Clean up
    free(Ptr);

    return 0;
}
