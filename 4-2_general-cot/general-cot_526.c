#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    // Calculate the size needed for the structure with the desired array size
    size_t size = sizeof(person) + 10; // Assuming name array size is 10
    person* p = malloc(size);

    if (p != NULL) {
        // Initialize the structure members
        p->age = 30;
        p->sex = 'M';
        snprintf(p->name, 10, "John Doe"); // Example name

        // Access and print the initialized values
        printf("Age: %d\n", p->age);
        printf("Sex: %c\n", p->sex);
        printf("Name: %s\n", p->name);

        // Don't forget to free the allocated memory
        free(p);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
