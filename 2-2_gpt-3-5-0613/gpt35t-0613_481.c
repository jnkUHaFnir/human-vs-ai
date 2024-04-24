#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    char* greeting = malloc(strlen("Hello, ") + strlen(name) + strlen("!\n") + 1);
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");
    printf("%s\n", greeting);
    return greeting;
}

In the C code, we allocate memory for the greeting using `malloc`. This ensures that the memory remains valid even after the function call. The returned pointer should now be properly formatted as a string in the Python code.

I've also added an adjustment for Windows systems in the Python code. For Windows, the library file should have a `.dll` extension instead of `.so`. You can modify this part if necessary.

Note that you'll need to compile the C code into a shared library (.so or .dll) before running the Python code. You can do this using a C compiler, such as GCC, with a command like:
