#include <pthread.h>
#include <iostream>
#include "matmul.h"

using namespace std;

int main(int argc, char* argv[])
{
  pthread_t* thread;
  int i;

  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " number_of_threads" << endl;
    exit(-1);
  }

  num_thrd = atoi(argv[1]);
  init_matrix(A);
  init_matrix(B);
  thread = (pthread_t*)malloc(num_thrd * sizeof(pthread_t));

  for (i = 0; i < num_thrd; i++)
  {
    matThread *parm = new matThread(); // Allocate new matThread for each thread
    parm->slice = i;

    if (pthread_create(&thread[i], NULL, multiply, (void*)parm) != 0)
    {
      cerr << "Can't create thread" << endl;
      free(thread);
      exit(-1);
    }
  }

  for (i = 0; i < num_thrd; i++) // Fixed loop condition
    pthread_join(thread[i], NULL);

  cout << "\n\n";
  print_matrix(A);
  cout << "\n\n\t * " << endl;
  print_matrix(B);
  cout << "\n\n\t = " << endl;
  print_matrix(C);
  cout << "\n\n";

  free(thread);

  return 0;
}
