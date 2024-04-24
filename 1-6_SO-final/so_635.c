    int **createArr(int x, int y) {
        int **arrPtr = malloc(x*sizeof(int*));
        int i, j;       //Loop indexes
        for (i = 0; i < x; ++i)
            arrPtr[i] = malloc(y*sizeof(int));
    
        for (i = 0; i < x; ++i) {
            for (j = 0; j < y; ++j) {
                arrPtr[i][j] = i + j;
            }
        }
        return arrPtr;   
    }