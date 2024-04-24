extern "C" 
{
    void* multiply(void* param)
    {
      ...
    }
}
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define SIZE 5
#define NUM_THREADS 5

typedef struct {
    int id;
    int slice;
    int dim;
} ThreadData;

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void init_matrix(int m[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            m[i][j] = rand() % 10 + 1;
}

void print_matrix(int m[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        printf("\n\t| ");
        for (j = 0; j < SIZE; j++) printf("%2d ", m[i][j]);
        printf("|");
    }
}

void* multiply(void* param) {
    ThreadData *data = (ThreadData*)param;
    int from = (data->slice * data->dim)/NUM_THREADS;
    int to = ((data->slice + 1) * data->dim)/NUM_THREADS;
    int i, j, k;

    for (i = from; i < to; i++) {
        for (j = 0; j < data->dim; j++) {
            C[i][j] = 0;
            for (k = 0; k < data->dim; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }

    free(param);
    pthread_exit(0);
}

int main() {
    pthread_t* thread = (pthread_t*) malloc(NUM_THREADS * sizeof(pthread_t));
    int i;

    init_matrix(A);
    init_matrix(B);

    for (i = 0; i < NUM_THREADS; i++) {
        ThreadData* data = (ThreadData*) malloc(sizeof(ThreadData));
        data->slice = i;
        data->dim = SIZE;

        if (pthread_create(&thread[i], NULL, multiply, data) != 0) {
            free(thread);
            printf("ERROR creating thread");
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) pthread_join(thread[i], NULL);
    printf("\n\n");
    
    print_matrix(A);
    printf("\n\n\t     *\n");
    print_matrix(B);
    printf("\n\n\t     =\n");
    print_matrix(C);
    printf("\n\n");
    
    free(thread);

    return 0;
}
