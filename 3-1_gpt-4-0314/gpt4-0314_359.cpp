extern "C" {
#include "matmul.h"
}
#include <iostream>
using namespace std;

void print_matrix(int m[SIZE][SIZE]) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    cout << "\n\t|";
    for (j = 0; j < SIZE; j++)
      cout << m[i][j];
    cout << "|";
  }
}
#ifndef matmul_h__
#define matmul_h__
#define SIZE 10

typedef struct {
  int dim;
  int slice;
} matThread;

int num_thrd;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
int m[SIZE][SIZE];

void init_matrix(int m[SIZE][SIZE]);

#ifdef __cplusplus
extern "C" {
#endif

void print_matrix(int m[SIZE][SIZE]);
void* multiply(void* matThread);

#ifdef __cplusplus
}
#endif

#endif // matmul_h__

4. Link together the object files into a shared library:

```bash
g++ -shared -o libMatmul.so matmul.o matmul_cpp.o
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "matmul.h"

// Size by SIZE matrices
// number of threads
matThread* parm = NULL;

int main(int argc, char* argv[]) {
  pthread_t* thread;  // pointer to a group of threads
  int i;
  if (argc != 2) {
    printf("Usage: %s number_of_threads\n", argv[0]);
    exit(-1);
  }
  num_thrd = atoi(argv[1]);
  init_matrix(A);
  init_matrix(B);
  thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));
  matThread* parm = malloc(sizeof(matThread));
  for (i = 0; i < num_thrd; i++) {
    parm->slice = i;
    // creates each thread working on its own slice of i
    if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0) {
      perror("Can't create thread");
      free(thread);
      exit(-1);
    }
  }
  for (i = 1; i < num_thrd; i++)
    pthread_join(thread[i], NULL);
  printf("\n\n");
  print_matrix(A);
  printf("\n\n\t *\n");
  print_matrix(B);
  printf("\n\n\t =\n");
  print_matrix(C);
  printf("\n\n");
  free(thread);

  return 0;
}
