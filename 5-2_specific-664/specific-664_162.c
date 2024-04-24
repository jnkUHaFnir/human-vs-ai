#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            int n;
            do {
                printf("Enter a value for array[%d][%d]: ", i, j);
                scanf("%d", &n);
                
                if(n < -99 || n > 99) {
                    printf("Value is out of range. Program will now exit.\n");
                    exit(1); // Stop the program
                } else {
                    array[i][j] = n;
                }
            } while(n < -99 || n > 99);
        }
    }

    // Print the result
    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            printf("array[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    return 0;
}
