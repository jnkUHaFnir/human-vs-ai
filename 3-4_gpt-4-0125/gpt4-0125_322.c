#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
    int age;
    char name[30];
};

int main() {
    struct info* Ptr = NULL;
    int num = 0;
    char inputName[30];

    while(1) {
        printf("Enter name (or type 'stop' to finish): ");
        scanf("%s", inputName);

        if(strcmp(inputName, "stop") == 0) {
            break;
        }

        // Reallocate memory to accommodate the new entry
        Ptr = (struct info *)realloc(Ptr, (num+1) * sizeof(struct info));
        if (Ptr == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        
        strcpy((Ptr+num)->name, inputName);
        printf("Enter age: ");
        scanf("%d", &(Ptr+num)->age);
        num++; // Increase count after each successful entry
    }

    // Display the information entered
    for(int i = 0; i < num; ++i) {
        printf("Name = %s, Age = %d\n", (Ptr+i)->name, (Ptr+i)->age);
    }
    
    // Free the allocated memory
    free(Ptr);

    return 0;
}
