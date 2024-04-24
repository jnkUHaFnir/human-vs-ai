    int **createArr(int x, int y)
    {
        int **arrPtr;
        int i, j;       //Loop indexes
        arrPtr = malloc(x*sizeof(int*));
        if (arrPtr == NULL) { /* always check the return of malloc */
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < x; ++i) {
            arrPtr[i] = malloc(y*sizeof(int));
            if (arrPtr[i] == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
        }
    
        for (i = 0; i < x; ++i) {
            for (j = 0; j < y; ++j) {
                arrPtr[i][j] = i + j;
            }
        }
        return arrPtr;   
    }