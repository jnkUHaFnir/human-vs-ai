    int malloc2d(int *** grid, int nrows, int ncols){
        int i;
        *grid = (int**)malloc( sizeof(int *) * nrows);
    
        if (grid == NULL){
            printf("ERROR: out of memory\n");
            return 1;
        }
    
        for (i=0;i<nrows;i++){
            
    		(*grid)[i] = (int*)malloc( sizeof(int) * ncols);
            if (grid[i] == NULL){
                printf("ERROR: out of memory\n");
                return 1;
            }
        }
        printf("Allocated!\n");
        return 0;
    }
    
    int main(int argc, char ** argv)
    {
        int ** grid;
    
        malloc2d(&grid, 10, 10);
        grid[5][6] = 15;
        printf("%d\n", grid[5][6]);
        return 0;
    }