#include <stdio.h>
#include <stdlib.h>

int main() {
    char answer;

    while (1) {
        printf("\n\nWould you like to run the program again? Type y or n, then hit Enter: ");
        scanf(" %c", &answer); // Notice the space before %c to consume any leading whitespace including '\n'

        if (answer == 'y') {
            // Your program logic here
            printf("Running the program again...\n");
        } else if (answer == 'n') {
            break; // Exit the loop
        } else { // Handle invalid input
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Consume remaining characters in input buffer
        }
    }

    return 0;
}
