#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int success;

    printf("Please enter a number: ");
    success = scanf("%d", &num);

    if (success == 1) {
        printf("You entered a valid number: %d\n", num);
    } else {
        printf("Invalid input. Please enter a valid number.\n");
        // Clear the input buffer
        while (getchar() != '\n') {}
    }

    return 0;
}
