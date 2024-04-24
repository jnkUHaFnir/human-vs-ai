#include <stdio.h>
#include <ctype.h>

int main() {
    char repeat;
    do {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);
        scanf(" %c", &repeat);  // Use a space before %c to consume any leading whitespace
        repeat = toupper(repeat);
        if (repeat != 'Y' && repeat != 'N')
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
        else if (getchar() != '\n')  // Check if there are extra characters
            printf("Invalid input. Please enter a single character.\n\n");
    } while (repeat != 'N' && repeat != 'Y');
    
    return 0;
}
