#include <stdio.h>

int main() {
    char answer;

    do {
        printf("Would you like to run the program again? Type y or n, then hit Enter: ");
        scanf(" %c", &answer); // Note the space before %c to consume leading whitespace

        if (answer == 'y') {
            // Your program logic here
            printf("Running the program again...\n");
        } else if (answer == 'n') {
            printf("Exiting the program.\n");
            break; // Exit the loop
        } else {
            printf("ERROR: Invalid input. Your answer must be either y or n.\n");
        }

        while (getchar() != '\n'); // Clear input buffer

    } while (answer != 'y' && answer != 'n');

    return 0;
}
