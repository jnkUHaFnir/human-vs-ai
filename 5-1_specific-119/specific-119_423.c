#include <stdio.h>

int main() {
    int num, count = 0;
    double sum = 0.0, average;

    printf("Enter numbers (enter any non-integer to stop): \n");

    // Keep reading integers until a non-integer is entered
    while(scanf("%d", &num) == 1) {
        sum += num;
        count++;
    }

    // Calculate the average
    if (count > 0) {
        average = sum / count;
        printf("Average of the numbers entered is: %.2f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}
