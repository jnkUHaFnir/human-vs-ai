#include <stdio.h>
#include <ctype.h>   // For isalnum function
#include <string.h>  // For strlen function

int main() {
    char name[128];

    // "fgets" reads an entire line including spaces, up to the size-1 length or until a newline is encountered.
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin)) {
        // Remove the newline character if it was read by fgets
        name[strcspn(name, "\n")] = 0;

        int isValid = 1; // Assume the input is valid initially
        size_t len = strlen(name);

        for (size_t i = 0; i < len; ++i) {
            if (!isalnum((unsigned char)name[i])) { // Check if character is not alphanumeric
                isValid = 0; // Not a valid character, input is invalid
                break;
            }
        }

        if (isValid) {
            printf("Matched\n");
        } else {
            printf("Invalid\n");
        }
    } else {
        printf("Error reading input\n");
    }

    return 0;
}
