#include <stdio.h>

int main() {
    int x, prevChar = -1;
    int currentChar = -1;

    while ((currentChar = getc(stdin)) != EOF) {
        if (currentChar == ' ' && prevChar == ' ') {
            // Do something when two consecutive whitespaces are detected
            printf("Two consecutive whitespaces found\n");
            // Handle the next set of data here
        } else if (currentChar == ' ') {
            // Handle single white space
            printf("Single whitespace found\n");
        } else {
            // Handle non-whitespace character
            ungetc(currentChar, stdin); // put back the non-whitespace character
            if (scanf("%d", &x) == 1) {
                // Handle integer input
                printf("Integer input: %d\n", x);
            } else {
                // Handle non-integer input
                printf("Non-integer input\n");
            }
        }

        prevChar = currentChar;
    }

    return 0;
}
