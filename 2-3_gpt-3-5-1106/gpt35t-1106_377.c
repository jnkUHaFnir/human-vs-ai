#include <stdio.h>
#define SIZE 5
int main(void)
{
    int hot=0, pleasant=0, cold=0;
    int sum=0, i=0, temp;
    double average;

    while(1)
    {
        printf("Enter temperature %d> (-99 to stop)",i+1);
        scanf("%d",&temp);
        if(temp == -99) // check if the input is -99
        {
            break; // exit the loop
        }
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
        i++; // increment the loop counter
    }
    if(i==0) // if the loop is never executed
    {
        printf("No temperature data entered\n");
        return 0;
    }
    average = (double) sum/i; // calculate the average using the number of temperatures entered

    printf("The Collection of hot days is %d\n",hot);
    printf("The Collection of pleasant days is %d\n",pleasant);
    printf("The Collection of cold days is %d\n",cold);
    printf("The Average temperature is %.2f\n",average);
    return 0;
}
