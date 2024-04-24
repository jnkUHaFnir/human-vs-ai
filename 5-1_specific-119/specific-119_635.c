#include <stdio.h>
#include <stdlib.h>

void createArr(int*** arrPtr, int x, int y);

int main() {

    int x, y;       //Dimension
    int i, j;       //Loop indexes
    int** arr = NULL;      //2D array pointer
    x = 3;
    y = 4;

    createArr(&arr, x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d\n", arr[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < x; ++i) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j;       //Loop indexes
    int** arr = malloc(x * sizeof(int*));
    for (i = 0; i < x; ++i)
        arr[i] = malloc(y * sizeof(int));

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            arr[i][j] = i + j;
        }
    }

    *arrPtr = arr;
}
