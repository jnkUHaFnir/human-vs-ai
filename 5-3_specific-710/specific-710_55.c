#include <stdio.h>

int main() {
    int arr[2][3]; // Assuming a 2x3 array for demonstration

    int r = 2; // Number of rows
    int c = 3; // Number of columns

    int numInputs = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(scanf("%d", &arr[i][j]) != 1) {
                printf("Insufficient data points entered.\n");
                return 1; // Or handle the error in a way appropriate for your program
            }
            numInputs++;
        }
    }

    printf("Successfully read %d numbers into the array.\n", numInputs);

    // You can use the array 'arr' here

    return 0;
}
