#include <stdio.h>
#include <string.h>

typedef struct _person {
    int age;
    char sex;
    char name[]; // flexible array member
} person;

// A workaround structure to mimic fixing the size for the name field
typedef struct _fixed_person {
    int age;
    char sex;
    char name[50]; // fixed-size array
} fixed_person;

int main() {
    // You cannot do this for a flexible array member:
    // person p1 = {10, 'm', "John Doe"}; // Error: incomplete type

    // But you can create a structure with a nested struct that mimics a flexible array member
    struct {
        person base; // Base _person struct without the flexible array
        char name_buffer[50]; // Additional space for what would be the flexible array
    } person_with_buffer = { {23, 'm'}, "John Doe"}; // Initialize the composite structure

    // Initialize the fixed-size structure
    fixed_person p1 = {10, 'm', "John"};

    // Accessing members
    printf("Name: %s\n", person_with_buffer.base.name);
    printf("Name from fixed struct: %s\n", p1.name);

    return 0;
}
person* create_person(const char* name, int age, char sex) {
    size_t name_len = strlen(name) + 1; // +1 for null terminator
    person* p = (person*)malloc(sizeof(person) + sizeof(char) * name_len);
    if (!p) return NULL;
    p->age = age;
    p->sex = sex;
    strcpy(p->name, name);
    return p;
}
void free_person(person* p) {
    free(p);
}
