#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    int invalidInput = 0;
    
    do {
        if (invalidInput) {
            printf("Invalid input. Please enter only a single character.\n\n");
            invalidInput = 0;
            while(getchar() != '\n'); // Clear the input buffer
        }
        
        printf("Do you want to try again? (Y/N): ");
        scanf(" %c", &repeat); // Add a space before %c to consume leading whitespace
        repeat = toupper(repeat);
        if (repeat != 'Y' && repeat != 'N') {
            invalidInput = 1;
        }

    } while (repeat != 'N' && repeat != 'Y'); 

    if (repeat == 'Y') {
        printf("User wants to try again.\n");
    } else {
        printf("User does not want to try again.\n");
    }

    return 0;
}
