#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    char str[50];
    long long int num;

    printf("Enter a number: ");
    fgets(str, 50, stdin);

    num = atoll(str);

    if(num < INT_MIN || num > INT_MAX)
    {
        printf("The number is out of int range. Please reinput the data.\n");
    }
    else
    {
        printf("This number is within the int range.\n");
    }

    return 0;
}
