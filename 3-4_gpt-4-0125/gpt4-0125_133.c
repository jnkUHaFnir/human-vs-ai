#include<stdio.h>
#include<ctype.h>

int main()
{
    int number, sum = 0, result;

    do
    {
        printf("Enter a number: ");
        result = scanf("%d", &number);

        if(result == 0) {
            // Input was not an integer. Clear the buffer.
            while(fgetc(stdin) != '\n');
        } else {
            sum += number;
        }
    } 
    while(number != 0); // Could also check for result != EOF to handle end-of-file conditions.

    printf("Sum = %d", sum);

    return 0;
}
