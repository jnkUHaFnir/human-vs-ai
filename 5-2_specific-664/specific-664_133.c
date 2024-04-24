#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, sum = 0;
    int success;

    do {
        printf("Enter a number: ");
        success = scanf("%d", &number);

        if (success != 1) {
            // Clear the input buffer
            while ((getchar()) != '\n');
            continue; // Skip the rest of the loop and start over
        }

        sum += number;
    } while (number != 0);

    printf("Sum = %d", sum);

    return 0;
}
