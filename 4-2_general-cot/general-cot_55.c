#include <stdio.h>

int main() {
    int r = 2; // Number of rows
    int c = 3; // Number of columns
    int arr[2][3];

    int totalInputs = 0;
    int expectedTotal = r * c;

    while (totalInputs < expectedTotal) {
        if (scanf("%d", &arr[totalInputs / c][totalInputs % c]) == 1) {
            totalInputs++;
        } else {
            printf("Incorrect input, please provide %d more integer(s)\n", expectedTotal - totalInputs);
            break; // Exit the loop if input format is incorrect
        }
    }

    // Output the 2D array for testing
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
