#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _person {
    int age;
    char sex;
    char name[]; // flexible array member
} person;

int main() {
    // Calculate necessary size
    size_t nameLength = strlen("John Doe") + 1; // +1 for '\0'
    person *p = malloc(sizeof(person) + nameLength * sizeof(char));
    if (p == NULL) {
        // Handle malloc failure...
        return -1;
    }
    
    // Initialize fields
    p->age = 30;
    p->sex = 'M';
    strcpy(p->name, "John Doe"); // Initialize dynamic array

    // Use the structure
    printf("Name: %s, Age: %d, Sex: %c\n", p->name, p->age, p->sex);

    // Don't forget to free the allocated memory
    free(p);

    return 0;
}
