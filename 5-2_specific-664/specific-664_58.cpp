#ifndef matmul_h__
#define matmul_h__

#define SIZE 10

typedef struct {
    int dim;
    int slice;
} matThread;

extern int num_thrd;
extern int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

extern void init_matrix(int m[SIZE][SIZE]);
extern void print_matrix(int m[SIZE][SIZE]);
extern void* multiply(void* matThread);

#endif
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
    int slice = s->slice;
    int D = 10;
    int from = (slice * D) / num_thrd;
    int to = ((slice + 1) * D) / num_thrd;
    int i, j, k;
    cout << "computing slice " << slice << " from row " << from << " to " << to - 1 << endl;
    for (i = from; i < to; i++) {
        for (j = 0; j < D; j++) {
            C[i][j] = 0;
            for (k = 0; k < D; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "finished slice " << slice << endl;
    return NULL;
}
#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "matmul.h"

using namespace std;

int main(int argc, char* argv[]) {
    pthread_t* thread;
    int i;
    if (argc != 2) {
        cout << "Usage:" << argv[0] << " number_of_threads" << endl;
        exit(-1);
    }
    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));
    for (i = 0; i < num_thrd; i++) {
        matThread* parm = new matThread();
        parm->slice = i;
        if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0) {
            cerr << "Can't create thread" << endl;
            free(thread);
            exit(-1);
        }
    }
    for (i = 0; i < num_thrd; i++) {
        pthread_join(thread[i], NULL);
    }
    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t *" << endl;
    print_matrix(B);
    cout << "\n\n\t=" << endl;
    print_matrix(C);
    cout << "\n\n";
    free(thread);

    return 0;
}

This code should fix the segmentation fault issue.
