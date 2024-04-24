    #include <stdio.h>
    #include <lapacke.h>
    
    /* returns an array of double*, all of which NULL */
    double **alloc_argv(unsigned rows) {
        double **matrix = malloc(rows * sizeof(double *));
        if (matrix == NULL) {
            fprintf(stderr, "malloc failed!\n");
    
        }
        if (!matrix) abort();
    
        for (unsigned row = 0; row < rows; row++) {
            matrix[row] = malloc(rows * sizeof(double *));
            if (matrix[row] == NULL) {
                fprintf(stderr, "malloc failed!\n");
            }
        }
        return matrix;
    }
    /* returns an array of int*, all of which NULL */
    int **alloc_argv_int(unsigned rows) {
        int **matrix = malloc(rows * sizeof(int *));
        if (matrix == NULL) {
            fprintf(stderr, "malloc failed!\n");
    
        }
        if (!matrix) abort();
    
        for (unsigned row = 0; row < rows; row++) {
            matrix[row] = malloc(rows * sizeof(int *));
            if (matrix[row] == NULL) {
                fprintf(stderr, "malloc failed!\n");
    
            }
        }
        return matrix;
    }
    int main() {
        int N = 1024;
        int NN = N*N;
        double ** M = alloc_argv(N*N);
    
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) {
                M[i][j] =  (double) i;
            }
    
        int pivotArray[N];
        int errorHandler;
        double * lapackWorkspace = malloc(N*N* sizeof(double *) );
        dgetrf_(&N, &N,  M[0], &N,  pivotArray, &errorHandler);
        printf("dgetrf eh, %d\n", errorHandler);
        dgetri_(&N, M[0], &N,  pivotArray,  lapackWorkspace, &NN, &errorHandler);
        printf("dgetri eh, %d\n", errorHandler);
    
    
        for (size_t row = 0; row < N; ++row) {
            for (size_t col = 0; col < N; ++col) {
                printf("%g",  M[row][col]);
                if (N - 1 != col) { printf(", "); }
            }
            if (N - 1 != row) { printf("\n"); }
        }
        return 0;
    }