#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define a structure to store names
struct Name {
    char name[MAX_NAME_LENGTH];
};

int main() {
    struct Name validName = {"Steve xyz @ //1"};
    char inputName[MAX_NAME_LENGTH];

    printf("Enter a name: ");
    fgets(inputName, MAX_NAME_LENGTH, stdin);

    // Remove newline character from inputName
    inputName[strcspn(inputName, "\n")] = '\0';

    // Compare the inputName with the validName
    if (strcmp(validName.name, inputName) == 0) {
        printf("Valid name!\n");
    } else {
        printf("Invalid name!\n");
    }

    return 0;
}
