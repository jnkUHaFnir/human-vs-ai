#include <stdio.h>
#include <stdlib.h>

int main() {
    int numOfDef;
    char input[100]; // Assuming a maximum input length of 100 characters

    do {
        printf("Enter a positive number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            return 1;
        }

        if (sscanf(input, "%d", &numOfDef) != 1 || numOfDef <= 0) {
            printf("Not a positive number. Please try again\n");
        }
    } while (numOfDef <= 0);

    printf("You entered a positive number: %d\n", numOfDef);

    return 0;
}
