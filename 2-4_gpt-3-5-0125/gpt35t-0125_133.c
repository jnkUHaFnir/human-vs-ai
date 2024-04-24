#include <stdio.h>
#include <ctype.h>

int main()
{
    int number, sum = 0;
    int read;

    do
    {
        printf("Enter a number: ");
        read = scanf("%d", &number); // store the return value of scanf

        if(read == 1) // check if scanf successfully read an integer
        {
            sum += number;
        }
        else
        {
            // clear the input buffer
            while(getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n");
        }

    } while(number != 0);

    printf("Sum = %d", sum);

    return 0;
}
