    #ifndef matmul_h__
    #define matmul_h__
    #define SIZE 10 
    #include <pthread.h>
    typedef struct {
        int dim;
        int slice;
    } matThread;
    // explicitly define as extern (for clarity)
    extern int num_thrd;
    extern int A[SIZE][SIZE];
    extern int B[SIZE][SIZE];
    extern int C[SIZE][SIZE];
    extern void init_matrix(int m[][SIZE]);
    extern void print_matrix(int m[][SIZE]);
    extern void* multiply(void* matThread);
    #endif