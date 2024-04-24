#include <stdio.h>

int main() {
    int x;
    int previousInput = ' ';
    int input;

    while ((input = getc(stdin)) != EOF) {
        if (input == ' ' && previousInput == ' ') {
            printf("Two consecutive whitespaces detected. Performing special action.\n");
            // Do something special with the next set of data
        } else if (input == ' ') {
            // Handle single whitespace
        } else {
            ungetc(input, stdin); // Put back the non-whitespace character
            if (scanf("%d", &x) == 1) {
                printf("Read integer: %d\n", x);
                // Process the integer
            } else {
                printf("Non-integer input detected. Exiting loop.\n");
                break;
            }
        }
        previousInput = input;
    }

    return 0;
}
