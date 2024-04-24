#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidName(const char* name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0;  // Invalid character found
        }
    }
    return 1;
}

void formatName(char* name) {
    for (int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);

    for (int i = 1; i < strlen(name); i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }
}

int main() {
    char name[15];  // Assuming the maximum length is 14 characters
    int valid = 0;

    do {
        printf("Enter your name: ");
        scanf("%14s", name);

        if (!isValidName(name)) {
            printf("Invalid character. Please enter a valid name.\n");
        } else {
            valid = 1;
        }
    } while (!valid);

    formatName(name);
    printf("Welcome, %s!\n", name);

    return 0;
}
