#include <stdio.h>

int main() {
    int num;
    int count = 0;
    double sum = 0, average;

    printf("Enter numbers (0 to terminate): \n");

    // Loop to read numbers until the user enters 0
    while (1) {
        scanf("%d", &num);
        if (num == 0) break; // Check for sentinel value
        
        sum += num; // Add current number to sum
        count++; // Increment count
    }

    // Calculate and display the average
    // Check to avoid division by zero
    if (count > 0) {
        average = sum / count;
        printf("Average of the entered numbers: %.2f\n", average);
    } else {
        printf("No valid numbers were entered.\n");
    }

    return 0;
}
