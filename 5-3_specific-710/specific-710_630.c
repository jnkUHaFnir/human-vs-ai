#include <stdio.h>
#include <stdlib.h>

int ** malloc2d(int nrows, int ncols) {
    int ** grid;
    int i;
    grid = malloc(sizeof(int *) * nrows);

    if (grid == NULL) {
        printf("ERROR: out of memory\n");
        exit(1);
    }

    for (i = 0; i < nrows; i++) {
        grid[i] = malloc(sizeof(int) * ncols);
        if (grid[i] == NULL) {
            printf("ERROR: out of memory\n");
            exit(1);
        }
    }
    printf("Allocated!\n");
    return grid;
}

int main(int argc, char ** argv) {
    int ** grid;

    grid = malloc2d(10, 10);
    grid[5][6] = 15;
    printf("%d\n", grid[5][6]);

    // Don't forget to free the allocated memory
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
