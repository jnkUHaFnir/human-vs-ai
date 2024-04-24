#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidName(const char *name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Invalid character found
        }
    }
    return 1; // Name contains only alphabetic characters
}

void formatName(char *name) {
    // Convert all letters to lower case first
    for (size_t i = 0; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    // Capitalize the first letter
    name[0] = toupper(name[0]);

    // Capitalize first letter of each word after a space
    for (size_t i = 1; i < strlen(name); i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }
}

int main() {
    char name[100]; // Assuming max length of name is 100 characters

    do {
        printf("Enter your name: ");
        if (scanf("%99s", name) == 1) {
            if (isValidName(name)) {
                formatName(name);
                printf("Formatted name: %s\n", name);
                break;
            } else {
                printf("Invalid characters found. Please enter a valid name.\n");
            }
        } else {
            // Clear input buffer in case of invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid name.\n");
        }
    } while (1);

    return 0;
}
