#include <stdio.h>
#include <stdlib.h>

// LAPACK headers
extern "C" {
    // LAPACK functions for inverting a matrix
    void dgetrf_(int* M, int* N, double* A, int* lda, int* IPIV, int* INFO);
    void dgetri_(int* N, double* A, int* lda, int* IPIV, double* WORK, int* lwork, int* INFO);
}

int main() {
    // Your matrix inversion code using LAPACK here

    return 0;
}

Make sure you have properly installed LAPACK and BLAS libraries, and that the header files for LAPACK are accessible in your system. Also, double-check the installation path for the LAPACK library and adjust the compilation command accordingly.
