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
#include <iostream>
#include "matmul.h"

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
    std::cout << "\n\t|";
    for (int j = 0; j < SIZE; j++) {
      std::cout << m[i][j];
    }
    std::cout << "|";
  }
}

void* multiply(void* param)
{
  matThread* s = (matThread*)param;
  int slice1 = s->slice;
  int D = SIZE;
  int from = (slice1 * D) / num_thrd;
  int to = ((slice1 + 1) * D) / num_thrd;

  for (int i = from; i < to; i++) {
    for (int j = 0; j < D; j++) {
      C[i][j] = 0;
      for (int k = 0; k < D; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  }

  return NULL;
}
#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include "matmul.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " number_of_threads" << std::endl;
    exit(-1);
  }

  num_thrd = atoi(argv[1]);
  
  int** A = new int*[SIZE];
  int** B = new int*[SIZE];
  int** C = new int*[SIZE];

  for (int i = 0; i < SIZE; i++) {
    A[i] = new int[SIZE];
    B[i] = new int[SIZE];
    C[i] = new int[SIZE];
  }

  init_matrix(A);
  init_matrix(B);

  pthread_t* threads = new pthread_t[num_thrd];
  matThread** parms = new matThread*[num_thrd];

  for (int i = 0; i < num_thrd; i++) {
    parms[i] = new matThread();
    parms[i]->slice = i;

    if (pthread_create(&threads[i], NULL, multiply, (void*)parms[i]) != 0) {
      std::cerr << "Can't create thread" << std::endl;
      exit(-1);
    }
  }

  for (int i = 0; i < num_thrd; i++) {
    pthread_join(threads[i], NULL);
  }

  std::cout << "\n\n";
  print_matrix(A);
  std::cout << "\n\n\t * \n";
  print_matrix(B);
  std::cout << "\n\n\t = \n";
  print_matrix(C);
  std::cout << "\n\n";

  delete[] threads;

  for (int i = 0; i < SIZE; i++) {
    delete[] A[i];
    delete[] B[i];
    delete[] C[i];
  }
  
  delete[] A;
  delete[] B;
  delete[] C;
  
  return 0;
}

By making these changes, you should handle the threads correctly without encountering the segmentation fault issue.
