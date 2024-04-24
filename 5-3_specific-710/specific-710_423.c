#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int count = 0;
    double average;

    printf("Enter numbers (enter any non-integer character to stop): \t");
    
    // Keep looping and reading integers until a non-integer character is entered
    while (scanf("%d", &num) == 1) {
        sum += num;
        count++;
    }

    // Calculate the average
    if (count > 0) {
        average = (double)sum / count;
        printf("Average of the numbers entered: %f\n", average);
    } else {
        printf("No numbers entered.\n");
    }

    return 0;
}
