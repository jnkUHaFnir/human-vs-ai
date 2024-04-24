#include <stdio.h>
#include <stdlib.h>

void createArr(int** arrPtr, int x, int y);

int main() {
    int x = 3;       // Dimension
    int y = 4;       // Dimension

    int** arr = malloc(x * sizeof(int*)); // Allocate memory for x number of int pointers

    for (int i = 0; i < x; ++i) {
        arr[i] = malloc(y * sizeof(int)); // Allocate memory for y number of ints for each int pointer
    }

    createArr(arr, x, y);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d\n", arr[i][j]);
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

void createArr(int** arrPtr, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            arrPtr[i][j] = i + j;
        }
    }
}
