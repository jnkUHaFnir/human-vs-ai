#include <stdio.h>

int main() {
    char answer[2]; // Increase size to 2 to hold 'y'/'n' and the null terminator.

    do {
        printf("\nWould you like to run the program again? Type y or n, then hit Enter: ");
        scanf(" %c", &answer[0]); // Use space before %c to skip any whitespace characters.
        while (getchar() != '\n'); // Clear the input buffer.

        if (answer[0] == 'y') {
            // Place the code you want to rerun here, or call a function representing your program.
            printf("Running program again...\n");
        }
        else if (answer[0] == 'n') {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n.\n");
        }
    } while (answer[0] != 'n'); // Keep running as long as the input is not 'n'.

    return 0;
}
