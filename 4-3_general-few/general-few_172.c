#include <stdio.h>

int main() {
    char answer = 'a';
    
    while (answer != 'y' && answer != 'n') {
        printf("\nWould you like to run the program again? Type y or n and hit Enter: ");
        scanf(" %c", &answer); // Notice the space before %c to skip the newline
        
        if (answer == 'y') {
            printf("Program will restart...\n");
            // Add your program logic here
        } else if (answer == 'n') {
            printf("Exiting program...\n");
            break;
        } else {
            printf("ERROR: Invalid input. Please type either 'y' or 'n'\n");
        }
        
        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}
