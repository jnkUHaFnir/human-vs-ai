#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(char* name) {
    char* greeting = (char*) malloc(100);
    if (greeting == NULL) {
        return NULL;
    }
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    return greeting;
}

Please note that I also added proper type casting and encoding/decoding for utf-8 characters to pass the correct string format to C and back to Python. And remember to free the allocated memory with `ctypes.CDLL('libc.so.6').free(foo)` after using it in your Python code.
