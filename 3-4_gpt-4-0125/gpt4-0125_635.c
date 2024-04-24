#include <stdio.h>
#include <stdlib.h> // Needed for malloc

// Note the change in parameter from int** to int***
void createArr(int*** arrPtr, int x, int y);

int main() {

    int x, y; // Dimension
    int i, j; // Loop indexes
    int** arr; // 2D array pointer
    arr = NULL;
    x = 3;
    y = 4;

    createArr(&arr, x, y); // Note the & operator to pass the address of arr

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory to prevent memory leaks
    for (i = 0; i < x; ++i) {
        free(arr[i]); // Free each inner array
    }
    free(arr); // Finally, free the outer array

    return 0;
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j; // Loop indexes
    
    // Allocating memory for x number of int* (pointers to int)
    *arrPtr = malloc(x * sizeof(int*));
    for (i = 0; i < x; ++i) {
        // For each int*, allocate memory for y ints
        (*arrPtr)[i] = malloc(y * sizeof(int));
    }

    // Initialize array elements
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }
}
