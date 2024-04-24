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
extern void* multiply(void* param);

#endif
#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

// initialize a matrix
void init_matrix(int m[SIZE][SIZE])
{
    int val = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m[i][j] = val++;
        }
    }
}

void print_matrix(int m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        cout << "\n\t| ";
        for (int j = 0; j < SIZE; j++) {
            cout << m[i][j] << " ";
        }
        cout << "|";
    }
}

// thread function: taking "slice" as its argument
void* multiply(void* param)
{
    matThread* s = (matThread*)param;   // retrieve the slice info
    int slice1 = s->slice;
    int D = SIZE;
    int from = (slice1 * D) / num_thrd; // note that this 'slicing' works fine
    int to = ((slice1 + 1) * D) / num_thrd; // even if SIZE is not divisible by num_thrd

    cout << "computing slice  " << slice1 << " from row " << from << " to " << to - 1 << endl;

    for (int i = from; i < to; i++) {
        for (int j = 0; j < D; j++) {
            C[i][j] = 0;
            for (int k = 0; k < D; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "finished slice " << slice1 << endl;

    return NULL;
}
#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

int num_thrd;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " number_of_threads" << endl;
        exit(-1);
    }

    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    pthread_t* thread = (pthread_t*) malloc(num_thrd * sizeof(pthread_t));
    matThread* parm = new matThread[num_thrd];  // create an array of matThread structs

    for (int i = 0; i < num_thrd; i++) {
        parm[i].slice = i;
        // creates each thread working on its own slice of i
        if (pthread_create(&thread[i], NULL, multiply, (void*)&parm[i]) != 0) {
            cerr << "Can't create thread" << endl;
            free(thread);
            exit(-1);
        }
    }

    for (int i = 0; i < num_thrd; i++) {  // iterate over all threads
        pthread_join(thread[i], NULL);
    }

    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t *\n";
    print_matrix(B);
    cout << "\n\n\t=\n";
    print_matrix(C);
    cout << "\n\n";

    free(thread);
    delete[] parm;

    return 0;
}
