#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "matmul.h"

extern "C" {
    using namespace std;

    // ... your functions and code here ...
}
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "matmul.h"

extern "C" {
    using namespace std;

    // ... your main function and the rest ...
}
// ...
matThread* parm = new matThread[num_thrd];
// ...
// ...
if (pthread_create (&thread[i], NULL, multiply, (void*)&parm[i]) != 0)
// ...
// ...
delete[] parm;
// ...
