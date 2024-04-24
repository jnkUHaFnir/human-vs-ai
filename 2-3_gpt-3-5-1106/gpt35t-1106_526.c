#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char sex;
    char name[];
}person;

int main() {
    int name_length = 6;
    person *p1 = malloc(sizeof(person) + name_length * sizeof(char));
    p1->age = 25;
    p1->sex = 'm';
    strcpy(p1->name, "John");

    // Now p1 is initialized with the given values

    // Don't forget to free the allocated memory after use
    free(p1);
    return 0;
}
