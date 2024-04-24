#include <stdio.h>

#define MAX_LENGTH 10

int main() {
    char input[MAX_LENGTH + 1];  // +1 for null terminator

    printf("Enter a string: ");

    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (input[strlen(input) - 1] != '\n') {
            // Input exceeded the maximum allowed length
            printf("Input too long!\n");
            // Consume remaining characters from input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        else {
            // Remove the newline character from input
            input[strcspn(input, "\n")] = '\0';

            // Proceed with further processing
            printf("You entered: %s\n", input);
        }
    }

    return 0;
}
