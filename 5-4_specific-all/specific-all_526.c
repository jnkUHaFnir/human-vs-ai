#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
} person;

int main() {
    // Calculate the total size needed for the structure based on the size of the name array
    size_t total_size = sizeof(person) + sizeof(char) * 20; // Assuming a maximum name length of 20 characters

    // Allocate memory for the structure
    person *p1 = malloc(total_size);

    // Check if memory allocation was successful
    if (p1 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the structure
    p1->age = 30;
    p1->sex = 'm';
    strcpy(p1->name, "John Doe");

    // Access the values
    printf("Age: %d\n", p1->age);
    printf("Sex: %c\n", p1->sex);
    printf("Name: %s\n", p1->name);

    // Don't forget to free the allocated memory when done
    free(p1);

    return 0;
}
