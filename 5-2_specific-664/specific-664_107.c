// main.c

// Including necessary headers
extern "C"
{
#include <pthread.h>
}
#include <iostream>
#include <cstdlib>
#include "matmul.h"

using namespace std;

int main(int argc, char* argv[])
{
  // Checking command line arguments
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " number_of_threads" << endl;
    exit(-1);
  }

  // Retrieving number of threads
  num_thrd = atoi(argv[1]);

  // Initializing matrices A, B and C
  init_matrix(A);
  init_matrix(B);

  // Allocating memory for threads array
  pthread_t* thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));

  // Creating threads
  for (int i = 0; i < num_thrd; i++)
  {
    matThread* parm = new matThread(); // Creating a new instance for each thread
    parm->slice = i;

    if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0)
    {
      cerr << "Can't create thread" << endl;
      free(thread);
      exit(-1);
    }
  }

  // Joining threads
  for (int i = 0; i < num_thrd; i++)
    pthread_join(thread[i], NULL);

  cout << "\n\n";
  print_matrix(A);
  cout << "\n\n\t *";
  print_matrix(B);
  cout << "\n\n\t=";
  print_matrix(C);
  cout << "\n\n";

  // Freeing allocated memory
  free(thread);

  return 0;
}
