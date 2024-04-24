#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input data
    int n = 8; // initial number of elements
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Initialize array with sorted integers
    for (int i = 0; i < n; i++) {
        arr[i] = i+1; // Just an example. You can input your own data.
    }

    // Loop to repeatedly halve the number of elements
    while (n > 1) {
        int* newArr = (int*)malloc(sizeof(int) * (n/2));
        if (newArr == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            free(arr);
            return 1;
        }

        // Add consecutive numbers
        for (int i = 0; i < n/2; i++) {
            newArr[i] = arr[2*i] + arr[2*i + 1];
        }

        // Output the result for this iteration
        printf("Result after halving:\n");
        for (int i = 0; i < n/2; i++) {
            printf("%d ", newArr[i]);
        }
        printf("\n");

        // Free the original array
        free(arr);

        // Update the size and array pointer for the next iteration
        n = n/2;
        arr = newArr;
    }

    // Free the final array
    free(arr);

    return 0;
}
