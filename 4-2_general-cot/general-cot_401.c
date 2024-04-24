#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

void print_matrix(char* desc, int m, int n, double* a, int lda);

int main() {
    lapack_int n = 3, lda = 3, info, ipiv[3];
    double a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 10};

    print_matrix("Matrix A", n, n, a, lda);

    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, a, lda, ipiv);
    if (info != 0) {
        printf("Failed to compute LU decomposition\n");
        return info;
    }

    info = LAPACKE_dgetri(LAPACK_ROW_MAJOR, n, a, lda, ipiv);
    if (info != 0) {
        printf("Failed to invert the matrix\n");
        return info;
    }

    print_matrix("Inverted Matrix A", n, n, a, lda);

    return 0;
}

void print_matrix(char* desc, int m, int n, double* a, int lda) {
    int i, j;
    printf("\n%s\n", desc);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(" %6.2f", a[i * lda + j]);
        }
        printf("\n");
    }
}

This command links against the LAPACK and LAPACKE libraries for matrix inversion. Make sure you have installed the corresponding development packages for LAPACK and BLAS (liblapacke-dev, liblapacke, libblas-dev).

This code is a simple example to demonstrate matrix inversion using LAPACK in C. You can adapt it to work with larger matrices or integrate it into your existing program once you have verified that the inversion works correctly.
