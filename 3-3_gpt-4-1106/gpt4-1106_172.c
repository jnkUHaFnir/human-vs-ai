#include <stdio.h>

int main() {
    char answer[2]; // Make room for the character and the null terminator

    do {
        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter: ");

        // Read a single character and ignore the newline using " %c"
        scanf(" %c", &answer[0]);
        answer[1] = '\0'; // Explicitly null-terminate the array

        if (answer[0] == 'y') {
            // Rerun the code that you want to execute again here
            // (you should NOT call main() recursively)
        }
        else if (answer[0] == 'n') {
            printf("Exiting program.\n");
            break; // Exit the loop, thus exiting the program
        }
        else {
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Please try again.\n");
            // Ignore the rest of the line to handle the case where
            // user types more than one character before hitting enter
            while ((getchar()) != '\n');
        }
    } while (1); // Infinite loop - exit is handled within the loop

    return 0;
}
