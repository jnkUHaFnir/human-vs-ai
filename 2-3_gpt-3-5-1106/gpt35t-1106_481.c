#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* hello(char* name) {
    char* greeting = (char*)malloc(100 * sizeof(char)); // dynamically allocate memory
    if (greeting == NULL) {
        // handle memory allocation error
        return NULL;
    }
    
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    
    return greeting;
}
hello = ctypes.cdll.LoadLibrary('./hello.so')
name = "Frank"
c_name = ctypes.c_char_p(name)
foo = hello.hello(c_name)
print c_name.value
print ctypes.c_char_p(foo).value

# free the dynamically allocated memory
hello.free(c_name)
