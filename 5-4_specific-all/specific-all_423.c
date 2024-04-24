#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL;
    int num, sum = 0, count = 0;
    float average;

    printf("Enter numbers (enter a non-numeric value to stop):\n");

    while (scanf("%d", &num) == 1) {
        count++;
        sum += num;
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }

    if (count == 0) {
        printf("No numbers entered. Exiting.\n");
        return 1;
    }

    average = (float)sum / count;

    printf("Numbers entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\nAverage of the numbers: %.2f\n", average);

    free(numbers);
    return 0;
}
