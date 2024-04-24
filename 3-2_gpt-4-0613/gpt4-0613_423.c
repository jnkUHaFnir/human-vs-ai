#include <stdio.h>

int main() {
    int num, count = 0;
    float sum = 0, avg = 0;

    printf("Enter numbers (non-numeric to stop): \t");

    while (scanf("%d", &num) == 1) {
        sum += num;
        count++;
        avg = sum / count;
    }

    printf("Average of the input numbers: %.2f", avg);

    return 0;
}
