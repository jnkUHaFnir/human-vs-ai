#include <stdio.h>
#include <stdlib.h>

void createArr(int*** arrPtr, int x, int y);

int main() {
    int x = 3;      // Dimension
    int y = 4;
    int i, j;

    int** arr = NULL;
    
    createArr(&arr, x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < x; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j;
    
    // Allocate memory for rows
    *arrPtr = (int**)malloc(x * sizeof(int*));
    
    // Allocate memory for columns
    for (i = 0; i < x; ++i) {
        (*arrPtr)[i] = (int*)malloc(y * sizeof(int));
    }

    // Populate the array
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }
}
