// matmul.h
#ifndef matmul_h__
#define matmul_h__

#define SIZE 10

typedef struct {
    int dim;
    int slice;
} matThread;

extern void init_matrix(int m[SIZE][SIZE]);
extern void print_matrix(int m[SIZE][SIZE]);
extern void* multiply(void* param);

#endif

// matmul.c
#include <iostream>
#include "matmul.h"

using namespace std;

int num_thrd;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void init_matrix(int m[SIZE][SIZE]) {
    int i, j, val = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m[i][j] = val++;
        }
    }
}

void print_matrix(int m[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        cout << "\n\t|";
        for (j = 0; j < SIZE; j++) {
            cout << m[i][j];
        }
        cout << "|";
    }
}

void* multiply(void* param) {
    matThread* s = (matThread*)param;
    int D = SIZE;
    int from = (s->slice * D) / num_thrd;
    int to = ((s->slice + 1) * D) / num_thrd;
    // rest of the function remains the same
    // Note: Update the cout statements to use printf or cerr to ensure thread-safety
    return NULL;
}

// main.c remains the same

