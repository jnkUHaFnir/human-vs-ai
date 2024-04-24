#ifndef matmul_h__
#define matmul_h__
...
// Add functions here that will be used outside
extern "C" {
void init_matrix(int m[SIZE][SIZE]);
void print_matrix(int m[SIZE][SIZE]);
void* multiply(void* matThread);
}
...
#endif
...
// No need for extern "C" here
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "matmul.h"
...
// Rest of your implementation
...
// Use <iostream> without extern "C"
#include <iostream>
#include "matmul.h"
using namespace std;
...
// Make sure to delete parm if using new
delete parm;
...

And to compile the main program:

```sh
g++ -o main main.cpp -L. -lMatmul -lpthread
