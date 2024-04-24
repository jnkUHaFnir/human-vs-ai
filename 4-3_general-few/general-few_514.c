#include <stdio.h>

int main() {
    int x;
    int previousChar = EOF;
    int currentChar;

    while ((currentChar = getc(stdin)) != EOF) {
        if (currentChar == ' ') {
            if (previousChar == ' ') {
                // Two consecutive whitespaces found
                printf("Found two consecutive whitespaces!\n");
                // Do something different with the next set of data
            } else {
                // Single whitespace found
                printf("Found a single whitespace\n");
                // Handle accordingly
            }
        } else if (currentChar >= '0' && currentChar <= '9') {
            // Read integer
            ungetc(currentChar, stdin);
            if (scanf("%d", &x) == 1) {
                // Process the integer
                printf("Read integer: %d\n", x);
            } else {
                printf("Failed to read integer\n");
            }
        } else {
            // Non-integer, non-whitespace character found
            printf("Non-integer, non-whitespace character detected\n");
            // Handle accordingly
        }

        previousChar = currentChar;
    }

    return 0;
}
