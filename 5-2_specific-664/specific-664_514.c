#include <stdio.h>

int main() {
    int x;
    int lastChar = '\0';  // Initialize last character with null character

    while (1) {
        int input = getc(stdin);

        if (input == EOF) {
            break;  // End of file, exit the loop
        }

        if (input == ' ') {
            if (lastChar == ' ') {
                // Two consecutive whitespaces detected, do something different
                printf("Two consecutive whitespaces detected, handling differently.\n");
            } else {
                // Single whitespace detected
                printf("Single whitespace detected, handling normally.\n");
            }
        } else if (input == '\n') {
            // Newline character may indicate the end of a set of data
            printf("Newline detected, ending current set of data processing.\n");
        } else if (input >= '0' && input <= '9') {
            // Process integer input
            ungetc(input, stdin); // Push back integer character
            scanf("%d", &x);
            printf("Read integer: %d\n", x);
        }

        lastChar = input; // Update last character
    }

    return 0;
}
