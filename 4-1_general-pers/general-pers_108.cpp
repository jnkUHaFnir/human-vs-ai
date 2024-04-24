#ifndef matmul_h__
#define matmul_h__

#define SIZE 10 

typedef struct {
    int dim;
    int slice;
} matThread;

extern int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
extern int num_thrd;

void init_matrix(int m[SIZE][SIZE]);
void print_matrix(int m[SIZE][SIZE]);
void* multiply(void* matThread);

#endif
#include "matmul.h"
#include <iostream>

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
            cout << m[i][j] << " ";
        }
        cout << "|";
    }
}

void* multiply(void* param) {
    matThread* s = (matThread*)param;
    int slice1 = s->slice;
    int D = SIZE;
    int from = (slice1 * D) / num_thrd;
    int to = ((slice1 + 1) * D) / num_thrd;

    for (int i = from; i < to; i++) {
        for (int j = 0; j < D; j++) {
            C[i][j] = 0;
            for (int k = 0; k < D; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return NULL;
}
#include "matmul.h"
#include <pthread.h>
#include <iostream>

using namespace std;

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
int num_thrd;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " number_of_threads" << endl;
        return -1;
    }

    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    pthread_t* thread = new pthread_t[num_thrd];

    for (int i = 0; i < num_thrd; i++) {
        matThread* parm = new matThread();
        parm->slice = i;

        if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0) {
            cerr << "Error creating thread" << endl;
            delete[] thread;
            return -1;
        }
    }

    for (int i = 0; i < num_thrd; i++) {
        pthread_join(thread[i], NULL);
    }

    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t *\n";
    print_matrix(B);
    cout << "\n\n\t =\n";
    print_matrix(C);
    cout << "\n\n";

    delete[] thread;

    return 0;
}
