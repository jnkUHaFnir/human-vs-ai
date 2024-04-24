#include <stdio.h>

int main() {
    int r = 2; // number of rows
    int c = 3; // number of columns
    int arr[r][c];

    int totalInputs = 0;
    int num;
    while (totalInputs < r * c) {
        if (scanf("%d", &num) == 1) {
            arr[totalInputs / c][totalInputs % c] = num;
            totalInputs++;
        } else {
            printf("Invalid input. Please enter integers only.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
    }

    if (totalInputs < r * c) {
        printf("Insufficient data points entered.\n");
        return 1;
    }

    // Print the 2D array as a check
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
