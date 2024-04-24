#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[128];

    // Prompt user for input
    printf("Enter a name: ");

    // Read a line of input safely. Note: fgets includes the newline character in the input buffer
    if (fgets(name, sizeof(name), stdin)) {
        // Check for and remove any trailing newline character
        name[strcspn(name, "\n")] = 0;

        int valid = 1; // Assume input is valid initially
        // Iterate over each character to check for alphanumeric
        for (int i = 0; name[i] != '\0'; i++) {
            if (!isalnum((unsigned char)name[i])) { // Use isalnum to check if alphanumeric
                valid = 0; // Mark input as invalid if a non-alphanumeric character is found
                break;
            }
        }

        if (valid) {
            printf("Matched\n");
        } else {
            printf("Invalid\n");
        }
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
