#include <stdio.h>

int main() {
    int x;
    int prevChar = ' ';
    int currentChar;

    // Read characters until the end of input
    while ((currentChar = getc(stdin)) != EOF) {
        // Check if the current character is a whitespace and the previous character was also a whitespace
        if (currentChar == ' ' && prevChar == ' ') {
            // Handle two consecutive whitespaces
            printf("Two consecutive whitespaces detected\n");
            // Do something different with the next set of data
        } else if (currentChar == ' ') {
            // Handle single whitespace
            printf("Single whitespace detected\n");
        } else {
            // Handle non-whitespace character
            // Convert character to integer if needed
            if (prevChar == ' ') {
                printf("New data set detected\n");
            } else {
                // Convert character to integer if needed
                // For example, x = currentChar - '0';
                // Process the integer value
                printf("Integer: %d\n", currentChar - '0');
            }
        }
        prevChar = currentChar;
    }

    return 0;
}
