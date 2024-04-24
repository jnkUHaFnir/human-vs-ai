#include <stdio.h>

int main() {
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            int value;
            do {
                printf("Value = ");
                scanf("%d", &value);
                if (value < -99 || value > 99) {
                    printf("Input out of bounds. Exiting...\n");
                    return 1; // Stop the program
                }
                array[i][j] = value;
            } while (array[i][j] < -99 || array[i][j] > 99);
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
