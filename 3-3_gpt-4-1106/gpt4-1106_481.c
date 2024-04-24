#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* hello(const char* name) {
    const char* greeting_prefix = "Hello, ";
    size_t greeting_size = strlen(greeting_prefix) + strlen(name) + 2; // +2 for exclamation and null terminator
    char* greeting = (char*)malloc(greeting_size);
    
    if (greeting == NULL) {
        return NULL; // Allocation failed
    }

    strcpy(greeting, greeting_prefix);
    strcat(greeting, name);
    strcat(greeting, "!\n");
    
    return greeting;
}
void free_hello(char* greeting) {
    free(greeting);
}

Keep in mind that Python 3 uses Unicode strings, so you need to encode/decode strings when using `ctypes.c_char_p`.

Remember to include header guards and the ifdefs necessary for exporting functions from a shared library in your C code, depending on your platform and compiler:
```c
#ifdef _WIN32
# define EXPORT __declspec(dllexport)
#else
# define EXPORT
#endif

EXPORT char* hello(const char* name);
EXPORT void free_hello(char* greeting);

On Windows, you would probably use:
```sh
gcc -shared -o hello.dll hello.c
