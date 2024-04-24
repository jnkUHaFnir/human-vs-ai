
Adding `-lpthread` at the end of the compilation command will link the pthread library which is necessary for pthread functions to work.

2. Check for any compilation errors or warnings that might be causing the issue. Make sure that there are no syntax errors or missing includes in your code.

3. Make sure that the pthread library is installed on your system. If not, you can install it using the following command:

```bash
sudo apt-get install libpthread-stubs0-dev

5. If none of the above solutions work, try running the compilation and linking commands in separate steps to see if there are any specific errors during each step:

```bash
g++ -c -Wall -fPIC matmul.cpp -o matmul.o
g++ -shared -o libMatmul.so matmul.o
