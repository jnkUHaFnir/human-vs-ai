#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person person1;
    strcpy(person1.name, "Steve xyz");

    char inputName[50];
    printf("Enter a name: ");
    fgets(inputName, 50, stdin);

    // Removing the newline character from inputName
    inputName[strcspn(inputName, "\n")] = 0;

    if (strcmp(person1.name, inputName) == 0) {
        printf("Valid name entered.\n");
    } else {
        printf("Invalid name entered.\n");
    }

    return 0;
}
