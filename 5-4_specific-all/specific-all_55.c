#include <stdio.h>
#include <stdlib.h>

int main() {
    int r = 2; // Number of rows
    int c = 3; // Number of columns
    int arr[r][c];

    int num;
    int count = 0;

    while (count < r * c && scanf("%d", &num) == 1) {
        arr[count / c][count % c] = num;
        count++;
    }

    if (count != r * c) {
        printf("Insufficient datapoints provided.\n");
        // Additional error handling if needed
    }

    // Print the 2D array for verification
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
