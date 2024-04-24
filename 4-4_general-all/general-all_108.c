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
extern void* multiply(void* matThread);

#endif

// matmul.c
#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

int num_thrd;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
pthread_mutex_t mutex;

void init_matrix(int m[SIZE][SIZE])
{
    int i, j, val = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            m[i][j] = val++;
}

void print_matrix(int m[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        cout << "\n\t|";
        for (j = 0; j < SIZE; j++)
            cout << m[i][j];
        cout << "|";
    }
}

void* multiply(void* param)
{
    matThread* s = (matThread*)param;
    int slice1 = s->slice;
    int D = 10;
    int from = (slice1 * D) / num_thrd;
    int to = ((slice1 + 1) * D) / num_thrd;
    
    for (int i = from; i < to; i++)
    {
        for (int j = 0; j < D; j++)
        {
            int sum = 0;
            for (int k = 0; k < D; k++)
                sum += A[i][k] * B[k][j];
            
            // Lock before modifying shared matrix C
            pthread_mutex_lock(&mutex);
            C[i][j] = sum;
            pthread_mutex_unlock(&mutex);
        }
    }
    
    return NULL;
}

// main.c
#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

int main(int argc, char* argv[])
{
    pthread_t* thread;
    
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " number_of_threads" << endl;
        return -1;
    }
    
    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    thread = new pthread_t[num_thrd];
    
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < num_thrd; i++)
    {
        matThread* parm = new matThread();
        parm->slice = i;
        
        if (pthread_create(&thread[i], nullptr, multiply, parm) != 0)
        {
            cerr << "Can't create thread" << endl;
            delete[] thread;
            return -1;
        }
    }
    
    for (int i = 0; i < num_thrd; ++i)
    {
        pthread_join(thread[i], nullptr);
    }
    
    cout << "\n\n";
    print_matrix(A);
    cout << "\n\n\t * " << endl;
    print_matrix(B);
    cout << "\n\n\t = " << endl;
    print_matrix(C);
    cout << "\n\n";
    
    delete[] thread;
    pthread_mutex_destroy(&mutex);

    return 0;
}
