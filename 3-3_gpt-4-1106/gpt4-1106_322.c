#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
    int age;
    char name[30];
};

int main() {
    struct info *Ptr = NULL; // Initialize to NULL for realloc
    int i = 0;
    char input[30]; // Buffer to check for 'stop'

    // Initially allocate memory for one person
    Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));

    while(1) {
        printf("Enter name (or type 'stop' to finish): ");
        scanf("%29s", input); // Use %29s to prevent buffer overflow

        if(strcmp(input, "stop") == 0) {
            break; // Exit loop when user types "stop"
        }

        strcpy(Ptr[i].name, input); // Copy the name into the struct

        printf("Enter age: ");
        scanf("%d", &Ptr[i].age);

        i++; // Increment index to move to the next person

        // Allocate more memory for another person
        Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));

        if (!Ptr) {
            fprintf(stderr, "Memory allocation failed!");
            return 1;
        }
    }

    printf("\nYou have entered the following information:\n");
    for(int j = 0; j < i; ++j) {
        printf("Name = %s, Age = %d\n", Ptr[j].name, Ptr[j].age);
    }

    // Free memory after use
    free(Ptr);

    return 0;
}
