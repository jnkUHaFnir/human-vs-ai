#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    size_t len = strlen(name) + strlen("Hello, ") + strlen("!\n") + 1;
    char* greeting = (char*)malloc(len);
    
    if (greeting == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    snprintf(greeting, len, "Hello, %s!\n", name);
    printf("%s\n", greeting);
    return greeting;
}
void free_string(char* str) {
    free(str);
}

By following these steps, you ensure proper memory management in the C code, making it safer to return dynamically allocated strings to be used in different languages through foreign function interfaces.
