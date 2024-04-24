#include <stdio.h>

int main() {
    int prevChar = ' ';
    int currChar;

    while ((currChar = getc(stdin)) != EOF) {

        if (currChar == ' ') {
            if (prevChar == ' ') {
                // Two consecutive whitespaces found, handle the scenario here
                printf("Two consecutive whitespaces detected.\n");
            } else {
                // Single whitespace found
                // Do something else
                printf("Single whitespace detected.\n");
            }
        } else {
            // Non-whitespace character found
            // Do something else
            printf("Non-whitespace character detected: %c\n", currChar);
        }

        prevChar = currChar;
    }

    return 0;
}
