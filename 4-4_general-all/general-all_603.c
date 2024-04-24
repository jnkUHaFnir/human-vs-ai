#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidName(const char *name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Return false if any non-alphabetic character is found
        }
    }
    return 1; // Return true if all characters are alphabetic
}

int main() {
    char name[50];

    do {
        printf("Enter your name: ");
        if (scanf("%49s", name) != 1) {
            printf("Please enter a valid name.\n");
            while (fgetc(stdin) != '\n'); // Clear input buffer
        } else if (!isValidName(name)) {
            printf("Invalid character. Please enter a valid name.\n");
        }
    } while (!isValidName(name));

    // Convert all letters to lowercase except for the first letter
    for (size_t i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    // Capitalize the first letter
    name[0] = toupper(name[0]);

    // Print the formatted name
    printf("Formatted name: %s\n", name);

    return 0;
}
