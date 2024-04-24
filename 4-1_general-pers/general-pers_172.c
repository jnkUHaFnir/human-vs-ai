#include <stdio.h>

int main() {
    char answer;
    
    do {
        printf("\n\nWould you like to run the program again? Type y or n. Then hit Enter: ");
        scanf(" %c", &answer); // Notice the space before %c to consume any leading whitespace

        while(getchar() != '\n'); // Clear input buffer

        if (answer == 'y') {
            // Your program logic goes here
            printf("Program is running again...\n");
        } else if (answer == 'n') {
            // Simply exit the loop if 'n' is entered
            break;
        } else {
            printf("ERROR: Invalid input was provided. Your answer must be either y or n.\n");
        }
    } while (1); // Infinite loop until 'n' is entered or an error handling mechanism is added

    printf("Program has ended.\n");
    return 0;
}
