#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
} Person;

int main() {
    Person person;
    char userInput[MAX_NAME_LENGTH];

    // Storing a sample name in the structure
    strncpy(person.name, "Steve", MAX_NAME_LENGTH);

    // Getting user input for comparison
    printf("Enter a name to compare with 'Steve': ");
    fgets(userInput, MAX_NAME_LENGTH, stdin);

    // Removing the newline character from the user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Comparing the input with the name in the structure
    if (strcmp(userInput, person.name) == 0) {
        printf("Names match!\n");
    } else {
        printf("Names do not match!\n");
    }

    return 0;
}
