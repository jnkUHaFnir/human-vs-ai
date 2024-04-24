#include <stdio.h>
#include <ctype.h>

int main()
{
    int number, sum = 0;
    int result;

    do
    {
        printf("Enter a number: ");
    
        result = scanf("%d", &number);

        if (result != 1) {
            // Input was not an integer. Clear the input buffer.
            while ((result = getchar()) != '\n' && result != EOF) { /* discard */ }
        } else {
            // Add the successfully scanned integer to sum.
            sum += number;
        }
    }
    while(number != 0); // This will only be true if 'number' was successfully scanned before.

    printf("Sum = %d\n", sum);

    return 0;
}
