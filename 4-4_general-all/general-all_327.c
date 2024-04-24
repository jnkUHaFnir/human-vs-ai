#include <stdio.h>

int main() {
    int numOfDef;

    // Use a do-while loop to repeatedly ask for input until a positive integer is entered
    do {
        printf("Enter a positive number: ");
        
        // Check if the input is a valid integer
        if (scanf("%d", &numOfDef) != 1) {
            // Clear input buffer in case of invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer.\n");
        } 
        // Check if the input is a positive number
        else if (numOfDef <= 0) {
            printf("Not a positive number. Please enter a positive integer.\n");
        }
    } while (numOfDef <= 0);

    printf("The positive number entered is: %d\n", numOfDef);

    return 0;
}
