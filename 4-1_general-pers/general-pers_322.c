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
    int i = 0;
    char stop[5] = "stop";
    char input[30];

    while (1) {
        printf("Enter name and age (type 'stop' to finish): ");
        scanf("%s", input);

        if (strcmp(input, stop) == 0) {
            break;
        }

        Ptr = realloc(Ptr, (num + 1) * sizeof(struct info));

        if (Ptr == NULL) {
            printf("Memory allocation failed\n");
            return 1; // Return error code
        }

        printf("Enter age: ");
        scanf("%d", &(Ptr[num].age));
        strcpy(Ptr[num].name, input);

        num++;
    }

    for (i = 0; i < num; i++) {
        printf("Name = %s, Age = %d\n", Ptr[i].name, Ptr[i].age);
    }

    free(Ptr); // Free dynamically allocated memory

    return 0;
}
