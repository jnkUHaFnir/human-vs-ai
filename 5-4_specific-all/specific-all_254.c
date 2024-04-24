#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person person1;
    strcpy(person1.name, "Steve xyz @ //1");

    char inputName[50];
    printf("Enter a name: ");
    fgets(inputName, sizeof(inputName), stdin);

    // Remove newline character from inputName
    inputName[strcspn(inputName, "\n")] = 0;

    if (strcmp(person1.name, inputName) == 0) {
        printf("Names match!\n");
    } else {
        printf("Names do not match.\n");
    }

    return 0;
}
