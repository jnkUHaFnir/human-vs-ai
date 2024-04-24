#include <stdio.h>
#include <ctype.h>

int main()
{
    int number, sum = 0;
    int scanfResult;

    do
    {
        printf("Enter a number: ");
        scanfResult = scanf("%d", &number);

        if (scanfResult == 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
        } else {
            sum += number;
        }
    }
    while (number != 0);

    printf("Sum = %d", sum);

    return 0;
}
