#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0;
    int count = 0;
    int* numbers = NULL;
    int num;

    printf("Enter numbers (Ctrl+D or Ctrl+Z to exit): \n");

    while (scanf("%d", &num) == 1) {
        count++;
        sum += num;
        numbers = (int*)realloc(numbers, count * sizeof(int)); // Dynamically expand the array
        numbers[count - 1] = num; // Store the number in the array
    }

    if (count == 0) {
        printf("No numbers entered.\n");
    } else {
        double average = (double)sum / count;
        printf("Average: %.2f\n", average);

        // Optional: Print all the numbers entered by the user
        printf("Numbers entered: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");

        free(numbers); // Free the dynamically allocated memory
    }

    return 0;
}
