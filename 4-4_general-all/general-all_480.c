#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
    int age;
    char name[30];
};

int main() {
    struct info *Ptr = NULL;
    int num = 0;
    int maxNum = 5; // Default initial size
    char input[30];

    // Allocate memory for initial structures
    Ptr = (struct info*)malloc(maxNum * sizeof(struct info));
    if (Ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        printf("Enter name and age (or 'stop' to exit):\n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0) {
            break;
        }

        // Increase memory allocation if needed
        if (num == maxNum) {
            maxNum *= 2; // Double the size
            struct info *temp = (struct info*)realloc(Ptr, maxNum * sizeof(struct info));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(Ptr);
                return 1;
            }
            Ptr = temp;
        }

        // Input name and age
        strcpy((Ptr+num)->name, input);
        scanf("%d", &(Ptr+num)->age);

        num++;
    }

    // Print the stored information
    for (int i = 0; i < num; i++) {
        printf("Name = %s, Age = %d\n", (Ptr+i)->name, (Ptr+i)->age);
    }

    // Free memory
    free(Ptr);

    return 0;
}
