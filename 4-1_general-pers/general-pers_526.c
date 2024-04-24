#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 50

typedef struct _person {
    int age;
    char sex;
    char name[];
} Person;

// Function to initialize a Person structure without using malloc
void initPerson(Person *p, int age, char sex, const char *name) {
    p->age = age;
    p->sex = sex;
    strncpy(p->name, name, MAX_NAME_SIZE - 1); // copy at most MAX_NAME_SIZE - 1 characters to prevent buffer overflow
    p->name[MAX_NAME_SIZE - 1] = '\0'; // ensure null-termination
}

int main() {
    // Define a Person structure with space for the flexible array member
    char buffer[sizeof(Person) + MAX_NAME_SIZE];
    Person *p = (Person*)buffer;

    // Initialize the Person structure
    initPerson(p, 30, 'M', "John Doe");

    // Access the values
    printf("Person: %s, %d, %c\n", p->name, p->age, p->sex);

    return 0;
}
