#define ROW 10
#define COL 20

int numbers[ROW][COL];
#include <stdlib.h>

int **numbers;

void allocateArray(int row, int col) {
    numbers = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        numbers[i] = malloc(col * sizeof(int));
}
