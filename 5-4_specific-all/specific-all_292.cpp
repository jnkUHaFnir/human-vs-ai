#ifndef matmul_h__
#define matmul_h__
#define SIZE 10 

typedef struct {
    int dim;
    int slice;
    int (*A)[SIZE];
    int (*B)[SIZE];
    int (*C)[SIZE];
} matThread;

extern void init_matrix(int m[SIZE][SIZE]);
extern void print_matrix(int m[SIZE][SIZE]);
extern void* multiply(void* param);

#endif
#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

void init_matrix(int m[SIZE][SIZE]) {
    int val = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m[i][j] = val++;
        }
    }
}

void print_matrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "\n\t|";
        for (int j = 0; j < SIZE; j++) {
            cout << m[i][j];
        }
        cout << "|";
    }
}

void* multiply(void* param) {
    matThread* s = (matThread*)param;
    int from = (s->slice * s->dim) / num_thrd;
    int to = ((s->slice + 1) * s->dim) / num_thrd;
    for (int i = from; i < to; i++) {
        for (int j = 0; j < s->dim; j++) {
            s->C[i][j] = 0;
            for (int k = 0; k < s->dim; k++) {
                s->C[i][j] += s->A[i][k] * s->B[k][j];
            }
        }
    }
    return nullptr;
}
#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include "matmul.h"

using namespace std;

int main(int argc, char* argv[]) {
    pthread_t* thread;
    if (argc != 2) {
        cout << "Usage:" << argv[0] << " number_of_threads" << endl;
        exit(-1);
    }
    num_thrd = atoi(argv[1]);

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    init_matrix(A);
    init_matrix(B);

    thread = new pthread_t[num_thrd];
    matThread* parms = new matThread[num_thrd];
    for (int i = 0; i < num_thrd; i++) {
        parms[i].slice = i;
        parms[i].dim = SIZE;
        parms[i].A = A;
        parms[i].B = B;
        parms[i].C = C;
        
        if (pthread_create(&thread[i], nullptr, multiply, &parms[i]) != 0) {
            cerr << "Can't create thread" << endl;
            delete[] thread;
            delete[] parms;
            exit(-1);
        }
    }

    for (int i = 0; i < num_thrd; i++) {
        pthread_join(thread[i], nullptr);
    }

    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t *\n";
    print_matrix(B);
    cout << "\n\n\t =\n";
    print_matrix(C);
    cout << "\n\n";

    delete[] thread;
    delete[] parms;

    return 0;
}

This should resolve the segmentation fault issue caused by shared access to global variables in a multi-threaded environment.
