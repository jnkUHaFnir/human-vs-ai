    #include <stdio.h>
    #include "matmul.h"
    int num_thrd = 1;
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE];
    // initialize a matrix
    void init_matrix(int m[][SIZE])
    {
        int i, j, val;
        for (i = 0, val = -1; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                m[i][j] = ++val;
            }
        }
    }
    void print_matrix(int m[][SIZE])
    {
        int i, j;
        for (i = 0; i < SIZE; i++) {
            printf("\n\t|");
            for (j = 0; j < SIZE; j++) {
                printf("%d", m[i][j]);
            }
            printf("|");
        }
    }
    // thread function: taking "slice" as its argument
    void* multiply(void* param)
    {
        matThread* s = (matThread*)param;   // retrive the slice info
        int slice1 = s->slice;
        int D = s->dim = 10;
        int from = (slice1 * D) / num_thrd; // note that this 'slicing' works fine
        int to = ((slice1+1) * D) / num_thrd; // even if SIZE is not divisible by num_thrd
        int i, j, k;
        printf("computing slice %d from row %d to %d\n", slice1, from, to-1);
        for (i = from; i < to; i++) {
            for (j = 0; j < D; j++) {
                C[i][j] = 0;
                for ( k = 0; k < D; k++) {
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        printf(" finished slice %d\n", slice1);
        return NULL;
    }