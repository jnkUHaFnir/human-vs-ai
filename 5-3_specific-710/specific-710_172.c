#include <stdio.h>

int main() {
    char answer;

    while (1) {
        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter: ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            // Run the program again
            printf("\nRunning the program again...\n");
        }
        else if (answer == 'n') {
            // Stop the program
            printf("\nExiting the program. Goodbye!\n");
            break;
        } 
        else {
            // Invalid input
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    return 0;
}
