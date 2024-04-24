#include <stdio.h>
#include <stdlib.h>

// Function to add consecutive elements in the array and update the array pointer
int* addConsecutive(int* arr, int n) {
    int* newArr = malloc((n/2) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < n/2; i++) {
        newArr[i] = arr[2*i] + arr[2*i + 1];
    }

    free(arr); // Free memory allocated for the original array
    return newArr;
}

int main() {
    int n = 8; // Initial number of elements
    int* arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Initialize array with sorted integers
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    while (n > 1) {
        // Add consecutive elements and update the array
        arr = addConsecutive(arr, n);
        n /= 2; // Update the number of elements
    }

    // Print the final result
    printf("Final result: %d\n", arr[0]);

    free(arr); // Free memory allocated for the final result array
    return 0;
}
