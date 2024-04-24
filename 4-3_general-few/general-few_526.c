#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    // Create an instance of the structure with flexible array member
    size_t name_size = 10; // specify the size of the name array
    person *p1 = malloc(sizeof(person) + name_size); // allocate memory for the structure and the flexible array member

    if (p1 != NULL) {
        // Initialize the fields
        p1->age = 30;
        p1->sex = 'M';
        strncpy(p1->name, "John Doe", name_size); // copy the name into the flexible array member

        // Access the fields
        printf("Age: %d\n", p1->age);
        printf("Sex: %c\n", p1->sex);
        printf("Name: %s\n", p1->name);

        // Don't forget to free the memory when done
        free(p1);
    } else {
        printf("Failed to allocate memory.\n");
    }

    return 0;
}
