#include <stdio.h>
#include <stdlib.h>

int main() {
    int numOfDef;

    while (1) {
        printf("Enter a positive number: ");
        if (scanf("%d", &numOfDef) == 1 && numOfDef > 0) {
            // If we get here, it means input was successfully read and it's a positive number.
            break; // Exit the loop.
        } else {
            // Invalid input, not an integer or not positive.
            printf("Not a positive number, try again.\n");
            // Clear the input buffer.
            while (getchar() != '\n');
        }
    }

    // Continue with the rest of your code.

    return 0;
}
