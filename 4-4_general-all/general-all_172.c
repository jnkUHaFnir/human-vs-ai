#include <stdio.h>

int main() {
    char answer;

    do {
        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.\n");
        scanf(" %c", &answer); // Use a space before %c to consume any leading whitespace or newline character
        
        if (answer == 'y') {
            // Run program again
            printf("\nRunning the program again...\n");
        } else if (answer == 'n') {
            // Exit the program
            printf("\nExiting the program...\n");
            break;
        } else {
            // Invalid input handling
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n.\n");
        }

        // Clear input buffer
        while (getchar() != '\n');

    } while (answer != 'n');

    return 0;
}
