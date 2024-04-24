#include <stdio.h>

int main() {
    int number;
    printf("Enter a number: ");
    if (scanf("%d", &number) == 1) {
        // The input is a valid integer
        printf("You entered a valid number: %d\n", number);
    } else {
        // The input is not a valid integer
        printf("Invalid input, not a number.\n");
    }

    return 0;
}
