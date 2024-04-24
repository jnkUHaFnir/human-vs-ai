#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, valid = 1;

    // Input validation for alphabetic characters
    do {
        valid = 1; // Assume valid until proven otherwise
        printf("Enter your name: ");
        if (fgets(name, sizeof(name), stdin)) { // Use fgets to prevent buffer overflow
            name[strcspn(name, "\n")] = 0; // Remove newline character
            for (i = 0; name[i] != '\0'; i++) {
                if (!isalpha(name[i])) {
                    printf("Invalid character. Please enter a valid name.\n");
                    valid = 0;
                    break;
                }
            }
        } else {
            // handle error or exit
        }
    } while (!valid);

    // Convert to lowercase
    for (i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    // Convert first letter to uppercase
    if (islower(name[0])) {
        name[0] = toupper(name[0]);
    }

    // Convert first letter of a name after a space to uppercase
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }

    printf("Formatted name: %s\n", name);

    return 0;
}
