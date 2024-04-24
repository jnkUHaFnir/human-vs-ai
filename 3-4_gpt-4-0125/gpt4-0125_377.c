#include <stdio.h>

int main(void) {
    int hot = 0, pleasant = 0, cold = 0;
    int sum = 0, temp;
    double average;
    int count = 0; // This variable will keep track of how many temperatures have been entered.

    while(1) { // Start an infinite loop that we will break out of manually.
        printf("Enter temperature %d> (-99 to stop): ", count + 1);
        scanf("%d", &temp);

        if(temp == -99) {
            break; // Exit the loop if the user enters -99.
        }

        sum += temp;
        count++; // Increment count as a valid temperature was entered.

        if(temp >= 85) {
            ++hot;
        } else if(temp >= 60) { // No need to check if it's <= 84, as it's implied.
            ++pleasant;
        } else {
            ++cold;
        }
    }

    if (count > 0){ // Prevent division by zero if -99 is entered first.
        average = (double)sum / count; // Use count to calculate average to avoid dividing by the pre-defined SIZE.
        
        printf("The Collection of hot days is %d\n", hot);
        printf("The Collection of pleasant days is %d\n", pleasant);
        printf("The Collection of cold days is %d\n", cold);
        printf("The Average temperature is %.2f\n", average);
    } else {
        printf("No temperatures were entered.\n");
    }

    return 0;
}
