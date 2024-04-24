#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int isNameEqual(struct Person p, const char* inputName) {
    return strcmp(p.name, inputName) == 0;
}

int main() {
    struct Person person;
    strcpy(person.name, "Steve xyz @ //1");
    person.age = 30;

    char inputName[MAX_NAME_LENGTH];
    printf("Enter a name: ");
    fgets(inputName, MAX_NAME_LENGTH, stdin);
    // Remove the newline character added by fgets
    inputName[strcspn(inputName, "\n")] = 0;

    if (isNameEqual(person, inputName)) {
        printf("The names match!\n");
    } else {
        printf("The names do not match!\n");
    }

    return 0;
}
