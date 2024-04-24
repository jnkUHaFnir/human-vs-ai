#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    char* greeting = (char*)malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    
    if (greeting == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");

    printf("%s\n", greeting);
    return greeting;
}

void cleanup(char* greeting) {
    free(greeting);
}

This approach addresses the memory management issue and ensures that the returned string is safe to be accessed in other languages.
