#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);                              
        scanf(" %c", &repeat);
        repeat = toupper(repeat);

        if (repeat != 'Y' && repeat != 'N') {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
        } else if (scanf("%*[^\n]") != 1) {
            scanf("%*c"); // Clear input buffer
            printf("Invalid input. Please enter a single character.\n\n");
            repeat = ' '; // Reset repeat to continue looping
        }

    } while (repeat != 'N' && repeat != 'Y');

    if (repeat == 'Y') {
        printf("Trying again...\n");
        // Add your retry logic here
    } else {
        printf("Exiting...\n");
    }
    
    return 0;
}
