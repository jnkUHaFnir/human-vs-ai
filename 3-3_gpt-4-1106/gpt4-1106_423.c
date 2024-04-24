#include <stdio.h>

int main() {
    int inputNumber;
    int count = 0;
    double sum = 0.0;

    printf("Enter numbers (enter 0 to finish): \n");

    while (1) {
        // Read a number from user input
        scanf("%d", &inputNumber);

        // Check for the terminating condition
        if (inputNumber == 0) {
            break;
        }

        sum += inputNumber;  // Add the number to the sum
        count++;            // Increment the count of numbers entered
    }

    // Check if any number was entered
    if (count > 0) {
        double average = sum / count;
        printf("Average of entered numbers: %f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}
