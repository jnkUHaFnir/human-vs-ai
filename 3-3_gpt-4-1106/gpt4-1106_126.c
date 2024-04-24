typedef struct {
    int size;  // size of array
    int *array;  // pointer to the first element of the array
} IntArray;
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;    // size of array
    int *array;  // pointer to the first element of the array
} IntArray;

int main() {
    IntArray myIntArray;

    // Set the size of the array
    myIntArray.size = 10; // for example, allocate space for 10 integers

    // Allocate memory for the array
    myIntArray.array = (int *)malloc(myIntArray.size * sizeof(int));

    // Check if memory allocation was successful
    if (myIntArray.array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    // Initialize or use the array
    for (int i = 0; i < myIntArray.size; ++i) {
        myIntArray.array[i] = i; // Assign some values to the array
    }

    // Example usage
    for (int i = 0; i < myIntArray.size; ++i) {
        printf("%d ", myIntArray.array[i]);
    }
    printf("\n");

    // Don't forget to free the allocated memory when you're done with it
    free(myIntArray.array);

    return 0;
}
