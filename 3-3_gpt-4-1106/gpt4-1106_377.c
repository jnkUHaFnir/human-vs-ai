#include <stdio.h>

int main(void)
{
    int hot = 0, pleasant = 0, cold = 0;
    int sum = 0, i, temp;
    double average;
    int count = 0; // Counter for the number of valid temperature entries

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter temperature %d> (-99 to stop): ", i+1);
        scanf("%d", &temp);

        if(temp == -99)
        {
            break; // Stop the loop if the user types -99
        }

        // Increment the number of valid temperature entries
        count++;
        sum += temp;

        if(temp >= 85)
        {
            ++hot;
        }
        else if(temp >= 60 && temp <= 84)
        {
            ++pleasant;
        }
        else
        {
            ++cold;
        }
    }

    if (count > 0) // Make sure we don't divide by zero
    {
        average = (double)sum / count;
    }
    else
    {
        average = 0.0;
    }

    printf("The Collection of hot days is %d\n", hot);
    printf("The Collection of pleasant days is %d\n", pleasant);
    printf("The Collection of cold days is %d\n", cold);
    if (count > 0) // Only show the average if it's meaningful
    {
        printf("The Average temperature is %.2f\n", average);
    }
    else
    {
        printf("No valid temperatures were entered.\n");
    }
    
    return 0;
}
