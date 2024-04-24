#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            int n;
            do {
                printf("Enter value for array[%d][%d]: ", i, j);
                scanf("%d", &n);
                if(n < -99 || n > 99) {
                    printf("Value out of range. Program will now exit.\n");
                    return 0;
                } else {
                    array[i][j] = n;
                }
            } while (n < -99 || n > 99);
        }
    }

    // Print the result
    printf("\nValues in the array:\n");
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            printf("[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
