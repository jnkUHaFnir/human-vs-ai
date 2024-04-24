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

        if(result != 1) {
            // Clear input buffer
            while ((result = getchar()) != '\n' && result != EOF);

            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        sum += number;
    }
    while(number != 0);

    printf("Sum = %d", sum);

    return 0;
}
