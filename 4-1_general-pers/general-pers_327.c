#include <stdio.h>

int main() {
    int numOfDef;

    do {
        printf("Enter a positive number: ");
        if (scanf("%d", &numOfDef) != 1 || numOfDef <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            // Clear input buffer
            while(getchar() != '\n');
        }
    } while (numOfDef <= 0);

    printf("You entered: %d\n", numOfDef);

    return 0;
}
