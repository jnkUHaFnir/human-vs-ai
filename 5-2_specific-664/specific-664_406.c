#include <stdio.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string (up to %d characters): ", MAX_INPUT_LENGTH - 1);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove trailing newline character if present
        input[strcspn(input, "\n")] = '\0';

        // Use the input as needed
        printf("You entered: %s\n", input);
    } else {
        // Handle error or end of file
        printf("Error reading input.\n");
    }

    return 0;
}
