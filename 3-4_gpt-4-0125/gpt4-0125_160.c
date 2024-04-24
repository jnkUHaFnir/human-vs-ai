#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    int validInput, extraChar;

    do {
        printf("Do you want to try again? (Y/N): ");
        validInput = scanf(" %c", &repeat); // Note the space before %c to skip whitespaces
        repeat = toupper(repeat);

        // Check if there are more characters on the same line.
        // If so, set validInput to 0 to signify invalid input.
        if (repeat != '\n') {
            while ((extraChar = getchar()) != '\n' && extraChar != EOF) {
                if (!isspace(extraChar)) { // Check for any non-space character
                    validInput = 0; // Invalidate the input
                }
            }
        }

        if (!validInput || (repeat != 'Y' && repeat != 'N')) {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
            validInput = 0; // Ensure loop continues on invalid input
        }
    } while (!validInput || (repeat != 'N'));

    return 0;
}
