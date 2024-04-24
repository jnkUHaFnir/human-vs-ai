#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num) == 1) {
        printf("You entered a valid integer: %d\n", num);
    } else {
        printf("Invalid input. Please enter a valid integer.\n");
    }

    return 0;
}
