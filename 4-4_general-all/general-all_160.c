#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);
        scanf(" %c", &repeat); // Read a single character
        
        // Check if the input is not a single character
        if (scanf("%*[^\n]%*c") != EOF) {
            printf("Invalid input. Please enter a single character.\n\n");
            repeat = ' '; // Reset repeat variable to continue the loop
        } else {
            repeat = toupper(repeat);
            if (repeat != 'Y' && repeat != 'N') {
                printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
            }
        }
    } while (repeat != 'N' && repeat != 'Y');

    return 0;
}
