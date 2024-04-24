#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* hello(const char* name) {
    char* greeting = (char*)malloc(100); // Dynamically allocate memory
    if (greeting == NULL) {
        return NULL; // Handle memory allocation failure
    }
    
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    
    printf("%s\n", greeting);
    return greeting;
}

void free_memory(char* ptr) {
    free(ptr);
}

In this Python code:
- We specify the return type of the `hello` function using `restype` to be `c_char_p`.
- We encode the `name` string to bytes before passing it to the C function.
- We call the `free_memory` function exposed by the C code to release the dynamically allocated memory when we're done with the returned string.

This way, you can properly handle memory allocation and deallocation in your C code to avoid segmentation faults and memory leaks when dealing with strings in multiple languages.
