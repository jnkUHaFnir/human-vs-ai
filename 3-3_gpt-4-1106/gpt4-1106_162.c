#include <stdio.h>

int main() {
    int array[2][2], i, j;

    // Iterate through each cell of the 2x2 array
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("Enter value for array[%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);

            // If the input is out of the specified range, end the program
            if (array[i][j] < -99 || array[i][j] > 99) {
                printf("Value out of bounds. Exiting program.\n");
                return 1; // Exit with a non-zero value to indicate an error
            }
        }
    }

    // Print the result
    printf("Array values:\n");
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0; // Exit normally
}
