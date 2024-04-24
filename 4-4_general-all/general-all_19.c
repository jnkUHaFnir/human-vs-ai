#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size; // size of array
    int *array;
} ArrayStruct;

int main() {
    ArrayStruct arr;
    int i;

    // Initialize the size of the array
    arr.size = 5; // for example purposes, can be any size

    // Allocate memory for the int array using the size variable
    arr.array = (int *)malloc(arr.size * sizeof(int));

    if (arr.array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array elements
    for (i = 0; i < arr.size; i++) {
        arr.array[i] = i; // assigning example values here
    }

    // Use the array
    printf("Array elements:\n");
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.array[i]);
    }

    // Free the allocated memory when done
    free(arr.array);

    return 0;
}
