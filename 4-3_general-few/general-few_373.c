#include <stdio.h>
#define SIZE 5

int main(void)
{
    int hot = 0, pleasant = 0, cold = 0;
    int sum = 0, i, temp;
    double average;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter temperature %d> (-99 to stop)", i + 1);
        scanf("%d", &temp);

        if (temp == -99)
        {
            break; // Exit the loop when -99 is entered
        }

        sum += temp;

        if (temp >= 85)
        {
            ++hot;
        }
        else if (temp >= 60 && temp <= 84)
        {
            ++pleasant;
        }
        else
        {
            ++cold;
        }
    }

    if (i == 0) // Handle case when -99 is entered as the first input
    {
        printf("No temperatures entered.\n");
        return 0;
    }

    average = (double)sum / i;

    printf("The Collection of hot days is %d\n", hot);
    printf("The Collection of pleasant days is %d\n", pleasant);
    printf("The Collection of cold days is %d\n", cold);
    printf("The Average temperature is %.2f\n", average);

    return 0;
}
