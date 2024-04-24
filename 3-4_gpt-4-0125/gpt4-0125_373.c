#include <stdio.h>
#define SIZE 5
int main(void)
{
    int hot=0, pleasant=0, cold=0;
    int sum=0, i, temp;
    double average;
    int count = 0; // To keep track of the actual number of inputs

    for(i=0; i<SIZE; i++)
    {
        printf("Enter temperature %d> (-99 to stop) ",i+1);
        scanf("%d",&temp);
        if(temp == -99)
        {
            break;
        }
        count++; // Update count for each valid temperature reading
        sum +=temp;

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
    if (count > 0) // To avoid division by zero if the first input is -99
    {
        average = (double) sum/count;
    }
    else // If first entered input is -99 or no valid inputs were entered
    {
        average = 0; // Default average to 0 or some other logic if no inputs are given
    }

    printf("\nThe Collection of hot days is %d\n",hot);
    printf("The Collection of pleasant days is %d\n",pleasant);
    printf("The Collection of cold days is %d\n",cold);
    printf("The Average temperature is %.2f\n",average);
    return(0);
}
