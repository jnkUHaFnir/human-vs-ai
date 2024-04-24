#include <stdio.h>
#include <stdlib.h>

int main() {
    int numOfDef;
    char input[100];
    while (1) {
        printf("Enter a positive number: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &numOfDef) == 1 && numOfDef > 0) {
                break;
            } else {
                printf("Invalid input. Please enter a positive number.\n");
            }
        }
        // Clear the input buffer
        while (getchar() != '\n');
    }

    printf("You entered: %d\n", numOfDef);

    return 0;
}
