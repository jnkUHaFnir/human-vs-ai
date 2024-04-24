#ifndef matmul_h__
#define matmul_h__
#define SIZE 10 

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int dim;
    int slice;
} matThread;

int num_thrd;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
int m[SIZE][SIZE];
void init_matrix(int m[SIZE][SIZE]);
void print_matrix(int m[SIZE][SIZE]);
void* multiply(void* matThread);

#ifdef __cplusplus
}
#endif

#endif
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "matmul.h"

using namespace std;

// initialize a matrix
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
        cout<<"\n\t|" ;
        for (j = 0; j < SIZE; j++)
            cout<<m[i][j] ;
            cout<<"|";
    }
}
// thread function: taking "slice" as its argument
void* multiply(void* param)
{
    matThread* s = (matThread*)param;   // retrive the slice info
    int slice1=s->slice;
    int D= s->dim=10;
    int from = (slice1 * D)/num_thrd; // note that this 'slicing' works fine
    int to = ((slice1+1) * D)/num_thrd; // even if SIZE is not divisible by num_thrd
    int i,j,k;
    cout<<"computing slice  " << slice1<<" from row "<< from<< " to " <<to-1<<endl;
    for (i = from; i < to; i++)
    {  
        for (j = 0; j < D; j++)
        {
            C[i][j] = 0;
            for ( k = 0; k < D; k++)
            C[i][j] += A[i][k]*B[k][j];
        }
    }
    cout<<" finished slice "<<slice1<<endl;
    return NULL;
}
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "matmul.h"
using namespace std;

// Size by SIZE matrices
// number of threads
matThread* parm=NULL;

int main(int argc, char* argv[])
{
    pthread_t* thread;  // pointer to a group of threads
    int i;
    if (argc!=2)
    {
        cout<<"Usage:"<< argv[0]<<" number_of_threads"<<endl;
        exit(-1);
    }
    num_thrd = atoi(argv[1]);
    init_matrix(A);
    init_matrix(B);
    thread = (pthread_t*) malloc(num_thrd*sizeof(pthread_t));
    matThread *parm = new matThread();
    for (i = 0; i < num_thrd; i++)
    {
    parm->slice=i;
        // creates each thread working on its own slice of i
        if (pthread_create (&thread[i], NULL, multiply, (void*)parm) != 0)
        {
            cerr<<"Can't create thread"<<endl;
            free(thread);
            exit(-1);
        }
    }
    for (i = 1; i < num_thrd; i++)
    pthread_join (thread[i], NULL);
    cout<<"\n\n";
    print_matrix(A);
    cout<<"\n\n\t *"<<endl;
    print_matrix(B);
    cout<<"\n\n\t="<<endl;
    print_matrix(C);
    cout<<"\n\n";
    free(thread);

    return 0;
}
