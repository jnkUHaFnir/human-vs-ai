#include <stdio.h>

#define MAX_NAME_SIZE 20

typedef struct {
    int age;
    char sex;
    char name[MAX_NAME_SIZE];
} Person;

int main() {
    Person p1 = {30, 'm'}; // Initialize age and sex directly
    
    // Initialize name using strcpy
    strcpy(p1.name, "John Doe");

    // Print the values
    printf("Person Details: \n");
    printf("Age: %d\n", p1.age);
    printf("Sex: %c\n", p1.sex);
    printf("Name: %s\n", p1.name);

    return 0;
}
