#include <stdio.h>

int main() {
    char answer;
    int flush; // to clear input buffer

    do {
        printf("\nWould you like to run the program again? Type y or n, then hit Enter.\n");
        scanf(" %c", &answer); // note the space before %c to consume any leading white space

        if (answer == 'y') {
            // Code to rerun the program goes here
            printf("\nRunning the program again...\n");
        } 
        else if (answer == 'n') {
            break; // Exit the loop and stop the program
        } 
        else {
            printf("\nERROR: Invalid input. Your answer must be either 'y' or 'n'.\n");
        }

        // Clear any remaining characters in the input buffer
        while ((flush = getchar()) != '\n' && flush != EOF);

    } while (answer != 'n');

    return 0;
}
