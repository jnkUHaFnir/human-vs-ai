#include <stdio.h>
#include <ctype.h>

int main() {
    int number, sum = 0;
    int result;

    do {
        printf("Enter a number: ");
        result = scanf("%d", &number);

        if (result == 1) {
            sum += number;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            // clear the input buffer
            while (getchar() != '\n'); // consume the invalid input
        }
    } while (result != 0);

    printf("Sum = %d", sum);

    return 0;
}
