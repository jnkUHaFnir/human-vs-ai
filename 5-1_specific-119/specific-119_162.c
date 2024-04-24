#include <stdio.h>

int main() {
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            int n;
            printf("Value at [%d][%d]= ", i, j);
            scanf("%d", &n);

            if (n < -99 || n > 99) {
                printf("Input value is out of bounds. Exiting...\n");
                return 1; // Exit the program with an error status
            }

            array[i][j] = n;
        }
    }

    // Print the result
    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            printf("\n[%d][%d]: %d", i, j, array[i][j]);
        }
    }

    return 0;
}
