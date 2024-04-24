#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    // Other fields...
} Person;

int main() {
    Person person;
    strcpy(person.name, "Steve xyz");

    char userInput[50];
    printf("Please enter your name: ");
    fgets(userInput, 50, stdin); // fgets includes the newline character

    // Remove newline character from userInput if present
    userInput[strcspn(userInput, "\n")] = 0;

    // Now compare the name in the structure with the one inputted by the user
    if (strcmp(person.name, userInput) == 0) {
        printf("Valid name!\n");
    } else {
        printf("Invalid name!\n");
    }

    return 0;
}
