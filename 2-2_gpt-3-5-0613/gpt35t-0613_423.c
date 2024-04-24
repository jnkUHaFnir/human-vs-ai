#include<stdio.h>

int main() {
    int num, count = 0;
    double sum = 0.0;

    printf("Enter numbers (press any non-numeric character to stop):\n");
    while (scanf("%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0) {
        double average = sum / count;
        printf("Average: %.2lf\n", average);
    } else {
        printf("No numbers entered.\n");
    }

    return 0;
}
