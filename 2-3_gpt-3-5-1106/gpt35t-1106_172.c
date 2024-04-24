#include <stdio.h>

int main() {
    char answer;

    do {
        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter: ");
        scanf(" %c", &answer);  // Notice the space before %c to consume any leading whitespace

        if (answer == 'y') {
            // Your program logic goes here
            printf("Running the program again...\n");
        } else if (answer != 'n') {
            printf("ERROR: Invalid input was provided. Your answer must be either 'y' or 'n'.\n");
        }
    } while (answer != 'n');

    return 0;
}
