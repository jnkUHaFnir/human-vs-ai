#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Assuming maximum length of the name is 100 characters
    int i, check;

    do {
        check = 0;
        printf("Enter your name: ");
        if (scanf("%99s", name) == 1) {
            for (i = 0; i < strlen(name); i++) {
                if (!isalpha(name[i])) {
                    printf("Invalid character. Please enter a valid name.\n");
                    check = 1;
                    break;
                }
            }
        } else {
            printf("Please enter a valid name.\n");
            check = 1;
            while (getchar() != '\n'); // Clear input buffer
        }
    } while (check == 1);

    // Convert all characters to lowercase
    for (i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }

    // Convert the first letter to uppercase
    name[0] = toupper(name[0]);

    // Convert first letter after a space to uppercase
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
    }

    printf("Normalized name: %s\n", name);

    return 0;
}
