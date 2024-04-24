#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    char* greeting = (char*)malloc(100 + strlen(name) + 2); // Allocate memory for greeting
    if (greeting == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    
    return greeting;
}

By explicitly allocating and freeing the memory for the returned string in C, you can avoid segfaults and undefined behavior when accessing the returned value in Python or any other language.
