#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);
        scanf(" %c", &repeat); // Note the space before %c to consume any leading whitespace
        repeat = toupper(repeat);
        
        if ((repeat != 'Y' && repeat != 'N') || (scanf("%*c") != EOF)) {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
            while (getchar() != '\n'); // Clear input buffer
        }

    } while (repeat != 'N' && repeat != 'Y'); 

    return 0;
}
