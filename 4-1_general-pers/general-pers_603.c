#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

int isAlphaString(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0; // Non-alphabetic character found
        }
    }
    return 1; // All characters are alphabetic
}

int main() {
    char name[MAX_NAME_LENGTH];

    // Input validation loop
    do {
        printf("Enter your name: ");
        if (scanf("%49s", name) != 1) {
            // Clear input buffer in case of invalid input
            while (getchar() != '\n');
            printf("Please enter a valid name.\n");
        } else if (!isAlphaString(name)) {
            printf("Invalid character. Please enter a valid name.\n");
        }
    } while (!isAlphaString(name));

    // Convert name to lowercase
    for (size_t i = 0; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    // Capitalize the first letter
    name[0] = toupper(name[0]);

    // Capitalize first letter of each word
    for (size_t i = 1; i < strlen(name); i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }

    printf("Processed name: %s\n", name);

    return 0;
}
