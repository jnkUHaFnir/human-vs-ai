#include<stdio.h>
#include<ctype.h>
int main()
{
    int number, sum = 0;
    int inputStatus; // To store the return value of scanf

    do
    {
        printf("Enter a number: ");
        inputStatus = scanf("%d", &number);

        if (inputStatus == 1) {
            sum += number;
        } else {
            // Clear the input buffer in case of non-integer input
            while (getchar() != '\n');
        }
    }
    while(inputStatus != 0);

    printf("Sum = %d",sum);
    return 0; // Adding a return statement to main is good practice
}
