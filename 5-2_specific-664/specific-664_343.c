#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100]; // Assuming a maximum length for the name
    
    // Loop until a valid input is provided
    while (1) {
        printf("Enter your name: ");
        if (scanf("%99s", name) == 1) {
            // Check if all characters are alphabetic
            int valid = 1;
            for (size_t i = 0; i < strlen(name); i++) {
                if (!isalpha(name[i])) {
                    valid = 0;
                    printf("Invalid character. Please enter a valid name.\n");
                    break;
                }
            }
            if (valid) {
                // Convert all characters to lowercase
                for (size_t i = 0; i < strlen(name); i++) {
                    name[i] = tolower(name[i]);
                }
                // Capitalize the first letter of each word
                name[0] = toupper(name[0]);
                for (size_t i = 1; i < strlen(name); i++) {
                    if (name[i - 1] == ' ') {
                        name[i] = toupper(name[i]);
                    }
                }
                printf("Valid name: %s\n", name);
                break;
            }
        } else {
            // Clear input buffer in case of invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    return 0;
}
