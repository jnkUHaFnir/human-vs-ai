#include <stdio.h>
#include <lapacke.h>

#define N 3  // Size of the square matrix

int main() {
    double A[N*N] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 10.0}; // Example matrix

    // Calculate the inverse of matrix A
    int ipiv[N]; // Pivot indices
    int info;
    
    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, N, N, A, N, ipiv);
    
    if (info == 0) {
        info = LAPACKE_dgetri(LAPACK_ROW_MAJOR, N, A, N, ipiv);
        if (info == 0) {
            // Print the inverted matrix
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%lf ", A[i*N + j]);
                }
                printf("\n");
            }
        } else {
            printf("Error in LAPACKE_dgetri\n");
        }
    } else {
        printf("Error in LAPACKE_dgetrf\n");
    }

    return 0;
}

Using the `-llapacke` flag should include the Lapack library for the Lapacke C interface.

Also, double-check the include path and library path for Lapack during compilation. If the issue persists, you may need to adjust the paths accordingly.
