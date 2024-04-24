mymatrixmalloc_2.c:15:18: fatal error: cstdio: non existing File or directory 
#include <cstdio>
#include <cstdio>
#include <stdio.h>

### LAPACK and BLAS Libraries

Given the commands you've used to install LAPACK and BLAS, and presuming those completed successfully, they should be installed and accessible on your system. The `-llapack -lblas` flags in your compile command are intended to link against these libraries, and the error you've encountered isn't related to the libraries not being found, but rather to the header issue described above.

### Installing Libraries (if necessary)

It looks like you've installed the libraries correctly, but for any readers who encounter issues finding the LAPACK or BLAS libraries, remember that on Ubuntu-based systems, you can install the development versions of these libraries to ensure you have the header files as well:
```bash
sudo apt-get install liblapack-dev libblas-dev
