#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

// Structure to store a person's name
struct Person {
    char name[MAX_NAME_LENGTH];
};

// Function to compare two names case-insensitively
int compareNames(const char* name1, const char* name2) {
    while (*name1 && *name2) {
        if (tolower(*name1) != tolower(*name2)) {
            return 0; // Names are different
        }
        name1++;
        name2++;
    }
    return (*name1 == '\0' && *name2 == '\0');
}

int main() {
    struct Person person;
    char inputName[MAX_NAME_LENGTH];

    // Get and sanitize user input for name
    printf("Enter a name: ");
    fgets(inputName, MAX_NAME_LENGTH, stdin);
    inputName[strcspn(inputName, "\n")] = '\0'; // Remove newline character if present

    // Compare the user input with the name in the structure
    if (compareNames(inputName, person.name)) {
        printf("Valid name entered.\n");
    } else {
        printf("Invalid name entered.\n");
    }

    return 0;
}
