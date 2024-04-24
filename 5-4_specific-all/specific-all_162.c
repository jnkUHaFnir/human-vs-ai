#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[2][2], i, j;

    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            int n;
            do {
                printf("Value for [%d][%d]= ", i, j);
                scanf("%d", &n);
                if(n < -99 || n > 99){
                    printf("Input value out of range [-99, 99]. Exiting.\n");
                    return 1; // Terminate the program
                }
                array[i][j] = n;
            } while(n < -99 || n > 99);
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
