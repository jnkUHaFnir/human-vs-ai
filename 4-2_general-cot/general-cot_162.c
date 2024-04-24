#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, j;

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            int n;
            do {
                printf("Value for array[%d][%d]: ", i, j);
                scanf("%d", &n);

                if (n > 99 || n < -99) {
                    printf("Input is out of bounds. Program will exit.\n");
                    exit(1); // Exit the program if input is out of bounds
                }

                array[i][j] = n;
            } while (n > 99 || n < -99);
        }
    }

    // Print the result
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("Array[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
