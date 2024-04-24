#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    // Calculate the total size needed for the structure including the size of the flexible array
    size_t total_size = sizeof(person) + 10 * sizeof(char); // Assuming a maximum name length of 10 characters

    // Allocate memory for the structure
    person *p1 = malloc(total_size);
    
    if (p1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the structure fields
    p1->age = 30;
    p1->sex = 'M';
    
    // Initialize the flexible array member (name)
    snprintf(p1->name, 10, "John Doe");

    // Access and print the initialized values
    printf("Age: %d\n", p1->age);
    printf("Sex: %c\n", p1->sex);
    printf("Name: %s\n", p1->name);

    // Don't forget to free the memory when done
    free(p1);

    return 0;
}
