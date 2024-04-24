#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidName(const char *name) {
    for (size_t i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; // Return 0 if any character is not alphabetic
        }
    }
    return 1; // Return 1 if all characters are alphabetic
}

int main() {
    char name[100]; // Define a buffer for the name
    int valid = 0;

    do {
        printf("Enter your name: ");
        scanf("%99s", name); // Limit input to prevent buffer overflow

        if (isValidName(name)) {
            valid = 1;
        } else {
            printf("Invalid name. Please enter alphabetic characters only.\n");
        }
    } while (!valid);

    // Convert to lowercase (except the first letter) and uppercase the first letter
    for (size_t i = 0; i < strlen(name); i++) {
        if (i == 0) {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
