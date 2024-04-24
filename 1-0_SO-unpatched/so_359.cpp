    gcc -c -Wall -fPIC matmul.c -o matmul.o
    gcc -shared -Wl,-soname,libMatmul.so -o libMatmul.so.1 matmul.o
    ln /full/path/to/libMatmul.so.1 /usr/lib/libMatmul.so
    gcc main.c -o matmul -Wall -L. -lMatmul -pthread