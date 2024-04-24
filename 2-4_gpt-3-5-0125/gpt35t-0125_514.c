#include <stdio.h>
#include <ctype.h>

int main() {
    int prevChar = EOF;
    int currentChar;
    int consecutiveWhitespace = 0;

    while ((currentChar = getc(stdin)) != EOF) {
        if (isspace(currentChar)) {
            if (isspace(prevChar)) {
                consecutiveWhitespace = 1;
            }
        } else {
            if (consecutiveWhitespace) {
                // Handle the next set of data differently
                printf("Next set of data will be handled differently\n");
                consecutiveWhitespace = 0;
            } else {
                // Handle the regular data processing
                printf("Regular data processing for: %c\n", currentChar);
            }
        }

        prevChar = currentChar;
    }

    return 0;
}
