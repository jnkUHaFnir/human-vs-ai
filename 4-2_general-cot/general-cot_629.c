#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidName(const char *name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Invalid character found
        }
    }
    return 1; // All characters are alphabetic
}

void formatName(char *name) {
    // Convert all characters to lower case except the first character
    for (size_t i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    // Capitalize the first character
    name[0] = toupper(name[0]);
    // Capitalize first letter of every word
    for (size_t i = 1; i < strlen(name); i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }
}

int main() {
    char name[100];
    int check = 0;

    do {
        printf("Enter your name: ");
        scanf("%s", name);

        check = isValidName(name);

        if (check == 0) {
            printf("Invalid character. Please enter a valid name.\n");
        }
    } while (check == 0);

    formatName(name);

    printf("Formatted name: %s\n", name);

    return 0;
}
