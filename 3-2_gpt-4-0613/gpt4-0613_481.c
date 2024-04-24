#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(char* name) {
    char *greeting;
    greeting = malloc(strlen(name) + 9); // 9 = length of "Hello, \n" + 1 for NULL termination`   
    if (greeting != NULL) {
        strcpy(greeting, "Hello, ");
        strcat(greeting, name);
        strcat(greeting, "!\n");
    }
    return greeting;
}

Now you should be able to run the python program without segfault.  

Note: Remember to call `free()` on returned memory after you're done with it in order to avoid memory leakage.
