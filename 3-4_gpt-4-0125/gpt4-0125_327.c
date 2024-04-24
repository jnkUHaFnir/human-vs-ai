#include <stdio.h>

int main() {
    int numOfDef;
    while (1) { // Infinite loop to keep trying until a valid input is received
        printf("Enter a positive number: ");
        int result = scanf("%d", &numOfDef);

        // Check if reading was successful and value is positive
        if (result == 1 && numOfDef > 0) {
            printf("You entered a positive number: %d\n", numOfDef);
            break; // Break the loop since a valid input was received
        } else {
            // Clear the buffer up to the next newline or EOF
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin)) {
                // No body needed; just consuming the buffer
            }
            printf("Not a positive number, try again.\n");
        }
    }

    return 0;
}
