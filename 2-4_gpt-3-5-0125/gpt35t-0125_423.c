#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int count = 0;
    double average;

    printf("Enter numbers (press Enter after each number, press any non-numeric key followed by Enter to end):\n");

    while (scanf("%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No numbers were entered.\n");
    } else {
        average = (double)sum / count;
        printf("Average of the numbers entered: %.2f\n", average);
    }

    return 0;
}
