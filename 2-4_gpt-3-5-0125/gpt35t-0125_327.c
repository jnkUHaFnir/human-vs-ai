#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[100];
    int numOfDef;

    do {
        printf("Enter a positive number: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &numOfDef) != 1 || numOfDef <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
        }
    } while (numOfDef <= 0);

    printf("You entered: %d\n", numOfDef);

    return 0;
}
