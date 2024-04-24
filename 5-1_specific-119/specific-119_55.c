#include <stdio.h>

int main() {
    int r = 2; // Number of rows
    int c = 3; // Number of columns
    int arr[r][c];

    int i, j;
    int numRead;

    // Assuming the user inputs the numbers separated by spaces like "1 2 3 4 5"
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            numRead = scanf("%d", &arr[i][j]);
            if (numRead != 1) {
                printf("Insufficient datapoints\n");
                return 1; // Exit the program or handle error appropriately
            }
        }
    }

    // Output the filled array for verification
    for(i = 0 ; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
