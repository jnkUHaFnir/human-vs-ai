#include <stdio.h>
#include <stdlib.h>

int* operateAndHalf(int* array, int size, int* newSize) {
    if (size <= 1) {
        *newSize = size;
        return array;
    }

    int newElements = size / 2;
    int* newArray = (int*)malloc(sizeof(int) * newElements);

    for (int i = 0; i < newElements; i++) {
        newArray[i] = array[2 * i] + array[2 * i + 1];

        // Additional operations can be performed here along with the addition
        // You can include any other operations you need before storing the result
    }

    free(array); // Free the original array

    return operateAndHalf(newArray, newElements, newSize);
}

int main() {
    int n = 8; // Example size of the initial array
    int* initialArray = (int*)malloc(sizeof(int) * n);

    // Fill the initial array with sorted integers as per your requirement
    // For simplicity, let's initialize it with some values
    for (int i = 0; i < n; i++) {
        initialArray[i] = i + 1;
    }

    int finalSize = 0;
    int* finalArray = operateAndHalf(initialArray, n, &finalSize);

    printf("Final result: %d\n", finalArray[0]);

    free(finalArray); // Free the final array after you are done using it

    return 0;
}
