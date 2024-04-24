#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* hello(char* name) {
    char* greeting = malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    if (greeting == NULL) {
        return NULL; // Error handling for memory allocation failure
    }

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    return greeting;
}
