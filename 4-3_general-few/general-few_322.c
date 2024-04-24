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
    int i = 0;  // Counter for the number of people
    int capacity = 2;  // Initial capacity
    char name[30];
    int age;
    char input[30];

    Ptr = (struct info*)malloc(capacity * sizeof(struct info));
    if (Ptr == NULL) {
        printf("Memory allocation failed");
        return -1;
    }

    printf("Enter name and age ('stop' to quit):\n");
    while (scanf("%s", name) == 1 && strcmp(name, "stop") != 0) {
        if (i == capacity) {
            capacity *= 2;
            Ptr = (struct info*)realloc(Ptr, capacity * sizeof(struct info));
            if (Ptr == NULL) {
                printf("Memory reallocation failed");
                return -1;
            }
        }
        strcpy((Ptr + i)->name, name);
        scanf("%d", &age);
        (Ptr + i)->age = age;
        i++;

        printf("Enter name and age ('stop' to quit):\n");
    }

    for (int j=0; j < i; ++j) {
        printf("Name = %s, Age = %d\n", (Ptr+j)->name, (Ptr+j)->age);
    }

    // Free allocated memory
    free(Ptr);

    return 0;
}
