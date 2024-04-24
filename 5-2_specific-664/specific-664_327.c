#include <stdio.h>

int main() {
    int numOfDef;

    // Prompt user until a valid positive integer is entered
    do {
        printf("Enter a positive number: ");
        
        // Check if the input is an integer and store the return value of scanf
        if (scanf("%d", &numOfDef) != 1) {
            printf("Invalid input. Please enter a positive number.\n");
            // Clear input buffer
            while (getchar() != '\n');
        } else if (numOfDef <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (numOfDef <= 0);

    printf("You entered: %d\n", numOfDef);

    return 0;
}
