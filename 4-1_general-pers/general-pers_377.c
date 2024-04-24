#include <stdio.h>
#define SIZE 5

int main(void)
{
    int hot = 0, pleasant = 0, cold = 0;
    int sum = 0, i, temp;
    double average;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter temperature %d> (-99 to stop): ", i + 1);
        scanf("%d", &temp);

        // Check for the stop condition
        if (temp == -99)
        {
            printf("Stop condition detected. Exiting the temperature input loop.\n");
            break;
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
    
    // Calculate average only if there are valid temperature inputs
    if (i > 0)
    {
        average = (double)sum / i;
        printf("The Collection of hot days is %d\n", hot);
        printf("The Collection of pleasant days is %d\n", pleasant);
        printf("The Collection of cold days is %d\n", cold);
        printf("The Average temperature is %.2f\n", average);
    }
    else
    {
        printf("No valid temperature inputs provided.\n");
    }

    return 0;
}
