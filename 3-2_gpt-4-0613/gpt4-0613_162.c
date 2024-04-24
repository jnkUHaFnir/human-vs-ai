#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[2][2];
    int i = 0, j = 0, n=0;

    do
    {
        for(i = 0; i < 2; i++){
            for(j = 0; j < 2; j++){
                printf("Value= ");
                scanf("%d", &n);

                if(n >= -99 && n <= 99){
                    array[i][j] = n;
                }else{
                    printf("Entered value is out of the permitted range. Exiting.\n");
                    exit(0); // exit the program if input is out of range
                } 
            }
        }
    }
    while(n >= -99 && n <= 99);

    // Print the result
    for(i = 0; i < 2; ++i){
        for(j = 0; j < 2; ++j){
            printf("[%d][%d]=%d ", i,j, array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
