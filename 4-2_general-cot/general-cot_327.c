#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int numOfDef = 0;

    do {
        printf("Enter a positive number: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Exiting...\n");
            return 1;
        }
        
        numOfDef = strtol(input, NULL, 10);

        if (numOfDef <= 0) {
            printf("Not a positive number. Please try again.\n");
        }
    } while (numOfDef <= 0);

    printf("You entered a positive number: %d\n", numOfDef);

    return 0;
}
