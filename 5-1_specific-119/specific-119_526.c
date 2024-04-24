#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    // Define the size of the flexible array member
    size_t name_size = 10;

    // Allocate memory for the entire structure including the flexible array member
    person *p1 = malloc(sizeof(person) + name_size);

    if (p1 != NULL) {
        // Initialize the structure fields
        p1->age = 30;
        p1->sex = 'M';
        
        // Initialize the flexible array member (name)
        snprintf(p1->name, name_size, "John Doe");
        
        // Access and print the values
        printf("Age: %d\n", p1->age);
        printf("Sex: %c\n", p1->sex);
        printf("Name: %s\n", p1->name);
        
        // Free the dynamically allocated memory
        free(p1);
    } else {
        // Handle failed memory allocation
        printf("Memory allocation failed\n");
    }

    return 0;
}
