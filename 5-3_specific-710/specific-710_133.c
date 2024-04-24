#include <stdio.h>
#include <ctype.h>

int main() {
    int number, sum = 0;
    int input_check;

    do {
        printf("Enter a number: ");
        input_check = scanf("%d", &number);

        // check if input was successfully read as an integer
        if (input_check == 1) {
            sum += number;
        } else {
            // clear input buffer
            while(getchar() != '\n');
        }
    } while(input_check == 1);

    printf("Sum = %d", sum);

    return 0;
}
