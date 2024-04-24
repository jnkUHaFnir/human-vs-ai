#include <stdio.h>
#include <ctype.h>

int main()
{
    int number, sum = 0;
    int result; // to store the return value of scanf

    do
    {
        printf("Enter a number: ");
        result = scanf("%d", &number);

        if (result == 1) {
            sum += number;
        } else {
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                continue;
        }
    }
    while (number != 0);

    printf("Sum = %d", sum);

    return 0;
}
