#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 8; // Initial size of the array
    int* originalArray = (int*)malloc(n * sizeof(int));
    
    // Initialize the original array with sorted integers
    for (int i = 0; i < n; i++) {
        originalArray[i] = i + 1; // example sorted integers
    }

    // Perform halving operation multiple times until only one element is left
    while (n > 1) {
        n /= 2;
        int* newArray = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            newArray[i] = originalArray[2*i] + originalArray[2*i + 1];
        }
        printArray(newArray, n);

        // Free the original array and update the pointer to the new array
        free(originalArray);
        originalArray = newArray;
    }

    // Free the final resulting array
    free(originalArray);

    return 0;
}
