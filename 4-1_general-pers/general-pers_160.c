#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);
        scanf(" %c", &repeat);
        repeat = toupper(repeat);
        
        if (!isalpha(repeat) || repeat != 'Y' && repeat != 'N') {
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
            while(getchar() != '\n'); // clear input buffer
        }

    } while (!isalpha(repeat) || repeat != 'N' && repeat != 'Y');

    return 0;
}
