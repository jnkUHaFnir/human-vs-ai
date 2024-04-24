#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gc.h>

int my_asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    // Determine the length of the formatted string
    va_list args_copy;
    va_copy(args_copy, args);
    int length = vsnprintf(NULL, 0, fmt, args_copy);
    va_end(args_copy);
    
    // Allocate memory using GC_malloc
    *strp = (char *)GC_MALLOC(length + 1);
    if (!*strp) {
        va_end(args);
        return -1; // Allocation failed
    }
    
    // Format the string
    vsnprintf(*strp, length + 1, fmt, args);
    
    va_end(args);
    
    return length;
}

// Usage example
static string printInt(Object self) {
    string str;
    my_asprintf(&str, "%lu", getValueInt(self));
    return str;
}
