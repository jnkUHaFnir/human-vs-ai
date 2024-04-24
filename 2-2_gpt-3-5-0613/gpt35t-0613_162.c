#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, n, j;

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            do {
                printf("Value [%d][%d]: ", i, j);
                scanf("%d", &n);
                if (n < -99 || n > 99) {
                    printf("Input out of range. Program terminated.\n");
                    return 0;
                }
                array[i][j] = n;
            } while (array[i][j] < -99 || array[i][j] > 99);
        }
    }

    // Print the result
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
