#include <stdio.h>

int main() {
    int numOfDef;
    // Loop until a positive integer is entered
    while(1) {
        printf("Enter a positive integer: ");
        if(scanf("%d", &numOfDef) == 1 && numOfDef > 0) {
            break; // Input is a positive integer, exit the loop
        } else {
            // Clear the input buffer
            while(getchar() != '\n');
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }

    printf("You entered: %d\n", numOfDef);

    return 0;
}
