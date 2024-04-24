#include <stdio.h>
#include <stdlib.h>

void createArr(int*** arrPtr, int x, int y);

int main() {

    int x, y;       //Dimension
    int i, j;       //Loop indexes
    int** arr;      //2D array pointer
    arr = NULL;
    x=3;
    y=4;

    createArr(&arr, x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d\n", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < x; ++i) {
        free(arr[i]);
    }
    
    free(arr);
    
    return 0;
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j;       //Loop indexes
    *arrPtr = malloc(x*sizeof(int*));
    for (i = 0; i < x; ++i)
        (*arrPtr)[i] = malloc(y*sizeof(int));

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }
}