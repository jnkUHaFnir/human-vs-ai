#include <stdio.h>
#include <stdlib.h>

int** createArr(int x, int y);

int main() {

    int x, y;       //Dimension
    int i, j;       //Loop indexes
    int** arr;      //2D array pointer
    x=3;
    y=4;

    arr = createArr(x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d\n", arr[i][j]);
        }
        printf("\n");
    }
    _getch();    
}

int** createArr(int x, int y) {
    int i, j;       //Loop indexes
    int** arrPtr = malloc(x*sizeof(int*));
    for (i = 0; i < x; ++i)
        arrPtr[i] = malloc(y*sizeof(int));

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            arrPtr[i][j] = i + j;
        }
    }
    
    return arrPtr;
}
