#define ROWS 3
#define COLS 3

int numbers[ROWS][COLS];
#include <stdio.h>

#define ROWS 3
#define COLS 3

int numbers[ROWS][COLS];

int main() {
    // Initialize the 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            numbers[i][j] = i * COLS + j;
        }
    }

    // Access and print elements of the 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}
