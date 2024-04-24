#include <stdio.h>
#include <ctype.h>

int main() {
    int number, sum = 0;
    int inputStatus; // to check the status of input

    do {
        printf("Enter a number: ");
        inputStatus = scanf("%d", &number);

        if (inputStatus == 1) {
            sum += number;
        } else {
            // clear the input buffer
            while (getchar() != '\n');
        }

    } while (number != 0);

    printf("Sum = %d", sum);

    return 0;
}
