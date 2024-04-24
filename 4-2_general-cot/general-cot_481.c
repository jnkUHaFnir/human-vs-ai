#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    char* greeting = (char*)malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    if (greeting == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    strcat(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    
    printf("%s\n", greeting);
    
    return greeting;
}

In the Python code snippet above, `hello.free` is called to explicitly free the memory allocated in C. This step is crucial to prevent memory leaks in your program.
