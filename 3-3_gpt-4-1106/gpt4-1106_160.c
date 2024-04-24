#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    int c;
    
    do {
        printf("Do you want to try again? (Y/N): ");
        repeat = getchar();
        repeat = toupper(repeat);
        
        // Check if there are any additional characters after the first one until a newline or EOF
        while ((c = getchar()) != '\n' && c != EOF) {
            /* Do nothing, or set a flag indicating invalid input if needed. */
        }
        
        // Conditions for invalid input: it is not 'Y'/'N' 
        // or there was some additional input before the newline.
        if (repeat != 'Y' && repeat != 'N' || c != '\n') {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
        }
        
    } while (repeat != 'N' && repeat != 'Y'); // Continue unless 'N' or 'Y' is entered.
    
    return 0;
}
