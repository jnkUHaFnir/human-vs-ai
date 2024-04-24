#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    char* greeting = (char*)malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    if (!greeting) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    return greeting;
}

In this Python code, we are correctly handling the encoding/decoding of strings between Python and C. This should prevent the segfault issue when trying to access the return value in Python.
