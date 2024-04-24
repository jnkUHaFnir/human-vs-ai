#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);                              
        scanf(" %c", &repeat); // Note the space before %c to consume leading whitespace
        repeat = toupper(repeat);
        if (repeat != 'Y' && repeat != 'N') {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
        } else if (getchar() != '\n') { // Check if more than one character was entered
            printf("Invalid input. Please enter a single character.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            repeat = ' '; // Reset repeat variable
        }
    } while (repeat != 'N' && repeat != 'Y');

    return 0;
}
