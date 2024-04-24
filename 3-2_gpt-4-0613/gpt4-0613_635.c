#include <stdio.h>
#include <stdlib.h>

void createArr(int*** arrPtr, int x, int y) {
    int i, j;       //Loop indexes
    *arrPtr = (int**)malloc(x*sizeof(int*));
    for (i = 0; i < x; ++i)
        (*arrPtr)[i] = (int*)malloc(y*sizeof(int));

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }    
}

int main() {

    int x, y;       //Dimension
    int i, j;       //Loop indexes
    int** arr;      //2D array pointer
    x=3;
    y=4;

    createArr(&arr, x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d\n", arr[i][j]);
        }
        printf("\n");
    }

    /* Freeing up allocated memory */
    for(i = 0; i < x; i++)
      free(arr[i]);
    free(arr);
}
