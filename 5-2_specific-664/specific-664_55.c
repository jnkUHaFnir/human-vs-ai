#include <stdio.h>

int main() {
    int r = 2; // Number of rows
    int c = 3; // Number of columns
    int arr[r][c]; // 2D array to store user input

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(scanf("%d", &arr[i][j]) != 1) {
                printf("insufficient datapoints\n");
                return 1; // Exit the program or handle the error accordingly
            }
        }
    }

    // Print the entered 2D array for verification
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
