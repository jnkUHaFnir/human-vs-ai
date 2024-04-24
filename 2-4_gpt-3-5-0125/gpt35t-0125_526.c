#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    int size = 10; // Example size for the flexible array
    person* p1 = malloc(sizeof(person) + size * sizeof(char));

    if (p1 != NULL) {
        p1->age = 20;
        p1->sex = 'm';
        
        // Initialize the flexible array
        for (int i = 0; i < size; i++) {
            p1->name[i] = 'a' + i; // Example initialization
        }

        // Print out the values for demonstration
        printf("Age: %d\n", p1->age);
        printf("Sex: %c\n", p1->sex);
        printf("Name: %s\n", p1->name);
        
        free(p1); // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
