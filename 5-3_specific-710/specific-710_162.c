#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            do {
                printf("Enter value for array[%d][%d]: ", i, j);
                scanf("%d", &array[i][j]);

                if(array[i][j] < -99 || array[i][j] > 99){
                    printf("Value out of range. Exiting...\n");
                    return 1; // Exit program
                }
            } while(array[i][j] < -99 || array[i][j] > 99);
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
