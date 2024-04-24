#include <stdio.h>
#include <ctype.h>

int main()
{
    int number, sum = 0;
    int success;

    do
    {
        printf("Enter a number: ");
        success = scanf("%d", &number);

        if (success == 0) {  // Input was not an integer
            while (getchar() != '\n');  // Clear input buffer
        } else {
            sum += number;
        }
    }
    while (number != 0);

    printf("Sum = %d", sum);

    return 0;
}
