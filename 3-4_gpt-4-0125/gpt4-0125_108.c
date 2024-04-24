
But, based on your description, you're dealing with `matmul.c` for the C code. In case you've incorrectly named your file as `.cpp` instead of `.c`, that can cause confusion in how the compiler treats the code, particularly with name mangling, since C++ applies name mangling and C does not.

Given your description and workflow, here's a step-by-step approach to compiling and linking your code into a shared library, assuming you fix any file naming inconsistencies:

### Step 1: Compile the C Code Correctly

If you're working with a C file, explicitly tell `g++` to treat it as such, or better, use `gcc` for C files:
```sh
gcc -c -Wall -fPIC matmul.c -o matmul.o
The `-x c` option tells `g++` to treat the following files as C code.

### Step 2: Linking to Create a Shared Library

Your command to create the shared library looks fine, assuming `matmul.o` correctly compiles:
```sh
g++ -shared -o libMatmul.so matmul.o
