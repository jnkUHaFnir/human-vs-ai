#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct Person person1;
    strcpy(person1.name, "Steve");
    person1.age = 30;

    char inputName[MAX_NAME_LENGTH];
    printf("Enter a name: ");
    fgets(inputName, MAX_NAME_LENGTH, stdin);
    inputName[strcspn(inputName, "\n")] = 0; // Remove newline character

    if(strcmp(inputName, person1.name) == 0) {
        printf("Valid name! Age: %d\n", person1.age);
    } else {
        printf("Invalid name!\n");
    }

    return 0;
}
