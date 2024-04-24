#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Structure definition
struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct Person person1;
    strncpy(person1.name, "Steve", MAX_NAME_LENGTH - 1); // Copying the name "Steve" into the structure
    person1.name[MAX_NAME_LENGTH - 1] = '\0'; // Ensuring null-termination of the string

    char userInput[MAX_NAME_LENGTH];
    printf("Enter a name: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character from user input
    size_t length = strlen(userInput);
    if (length > 0 && userInput[length - 1] == '\n') {
        userInput[length - 1] = '\0';
    }

    // Safe string comparison
    if (strncmp(person1.name, userInput, MAX_NAME_LENGTH) == 0) {
        printf("Names match!\n");
    } else {
        printf("Names do not match!\n");
    }

    return 0;
}
