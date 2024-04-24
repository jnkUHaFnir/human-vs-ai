#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen

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

    while(1) {
        printf("Enter name and age or type 'stop' to end:\n");
        if(scanf("%s", input) != 1 || strcmp(input, "stop") == 0) {
            break;
        }
        
        // Allocate memory for a new person
        struct info *temp = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));
        if(temp == NULL) {
            printf("Memory allocation failed\n");
            // Handle error if realloc fails
            break;
        }
        
        Ptr = temp;
        
        // Read in the name and age
        strcpy(Ptr[i].name, input);
        scanf("%d", &(Ptr[i].age));
        
        i++;
    }

    // Print the information
    for(int j = 0; j < i; ++j) {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    // Free the allocated memory
    free(Ptr);

    return 0;
}
