#include <stdio.h>
#include <stdlib.h>

int main() {
    char answer[2]; // Make space for at least 2 characters (1 for input, 1 for null terminator)
    char newline;

    do {
        printf("\n\nWould you like to run the program again? Type y or n and then hit Enter: ");
        scanf(" %c", answer); // Note the space before %c to consume any preceding whitespaces including '\n'

        while((newline = getchar()) != '\n' && newline != EOF); // Clear input buffer

        if (answer[0] == 'y') {
            // Add your program logic here
            printf("\nRunning the program again...\n");
        }
        else if (answer[0] == 'n') {
            printf("\nExiting the program...\n");
            break; // Exit the loop and end the program
        } 
        else {
            printf("\nERROR: Invalid input. Your answer must be either y or n. Press Enter to try again.\n");
        }

    } while(1); // Infinite loop until 'n' is entered

    return 0;
}
