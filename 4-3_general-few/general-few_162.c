#include <stdio.h>

int main() {
    int array[2][2], i, j;
    int flag = 1;

    while (flag) {
        flag = 0; // Assume the input is correct unless proven otherwise
        
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 2; ++j) {
                printf("Value for array[%d][%d]: ", i, j);
                scanf("%d", &array[i][j]);
                
                if (array[i][j] < -99 || array[i][j] > 99) {
                    printf("Error: Value out of bounds.\n");
                    flag = 1; // Set flag to indicate out of bounds
                    break;
                }
            }
            if (flag) { // Break outer loop if value is out of bounds
                break;
            }
        }
    }

    // Print the result
    printf("Array elements:\n");
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
