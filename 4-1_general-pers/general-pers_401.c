#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

#define N 3

int main() {
    double matrix[N*N] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    double inverse[N*N];

    // Lapack variables
    int ipiv[N];
    int info;

    // Compute the inverse
    LAPACKE_dgetrf(LAPACK_ROW_MAJOR, N, N, matrix, N, ipiv);
    LAPACKE_dgetri(LAPACK_ROW_MAJOR, N, matrix, N, ipiv);

    // Copy the result to the inverse matrix
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            inverse[i*N + j] = matrix[i*N + j];
        }
    }

    // Print the inverse matrix
    printf("Inverse Matrix:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%.2f ", inverse[i*N + j]);
        }
        printf("\n");
    }

    return 0;
}

This code should help you get the inverse of a matrix correctly using Lapack in C. Make sure you handle memory properly and check for errors returned by Lapack functions for a secure implementation.
