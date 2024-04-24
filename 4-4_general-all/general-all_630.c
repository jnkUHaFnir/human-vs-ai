#include <stdio.h>
#include <stdlib.h>

int malloc2d(int *** grid, int nrows, int ncols){
    int i;
    
    *grid = malloc(sizeof(int *) * nrows);
    
    if (*grid == NULL){
        printf("ERROR: out of memory\n");
        return 1;
    }

    for (i = 0; i < nrows; i++){
        (*grid)[i] = malloc(sizeof(int) * ncols);
        
        if ((*grid)[i] == NULL){
            printf("ERROR: out of memory\n");
            return 1;
        }
    }
    printf("Allocated!\n");
    return 0;
}

int main(int argc, char ** argv){
    int ** grid;

    if (malloc2d(&grid, 10, 10) == 0) {
        grid[5][6] = 15;
        printf("%d\n", grid[5][6]);
    }

    // Free the allocated memory
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
