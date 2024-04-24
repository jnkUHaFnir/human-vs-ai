#include <stdio.h>
#include <stdlib.h>

void createArr(int*** arrPtr, int x, int y);

int main() {
    int x = 3;       // Dimension
    int y = 4;       // Dimension

    int** arr = NULL; // 2D array pointer

    createArr(&arr, x, y);

    // Output the values of the 2D array
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < x; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j;       // Loop indexes

    // Allocate memory for the rows
    *arrPtr = (int**)malloc(x * sizeof(int*));
    if (*arrPtr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Allocate memory for each column
    for (i = 0; i < x; ++i) {
        (*arrPtr)[i] = (int*)malloc(y * sizeof(int));
        if ((*arrPtr)[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }

    // Populate the array with some values
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }
}
