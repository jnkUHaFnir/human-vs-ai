g++ -c -Wall -fPIC matmul.c -o matmul.o
g++ -shared -o libMatmul.so matmul.o
g++ matmul_test.cpp -o matmul_test -L. -lMatmul
LD_LIBRARY_PATH=. ./matmul_test <number_of_threads>
