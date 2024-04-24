#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* hello(char* name) {
    char* greeting = (char*)malloc(100); // Allocate memory for the return string
    if(greeting == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    snprintf(greeting, 100, "Hello, %s!\n", name); // Safely format the string

    printf("%s\n", greeting);
    return greeting;
}

void cleanup(const char* greeting) {
    free((void*)greeting); // Free the dynamically allocated memory
}
