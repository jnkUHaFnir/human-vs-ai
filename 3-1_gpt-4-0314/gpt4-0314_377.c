#include <stdio.h>

int main(void)
{
    int hot=0, pleasant=0, cold=0;
    int sum=0, i, temp;
    double average;

    i = 0;
    while(1) // Keep looping until -99 is entered
    {
        printf("Enter temperature %d> (-99 to stop): ",i+1);
        scanf("%d",&temp);

        if(temp == -99) // Break out of the loop if user inputs -99
        {
            break;
        }

        sum += temp;
        i++; // Increment day counter

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
    
    if(i != 0) // Avoid division by zero
    {
        average = (double) sum/i;

        printf("The Collection of hot days is %d\n",hot);
        printf("The Collection of pleasant days is %d\n",pleasant);
        printf("The Collection of cold days is %d\n",cold);
        printf("The Average temperature is %.2f\n",average);
    }
    else
    {
        printf("No temperatures were input, please provide some temperatures.\n");
    }
    
    return(0);
}
