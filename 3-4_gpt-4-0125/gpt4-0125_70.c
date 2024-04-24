#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int vasprintf(char **str, const char *fmt, va_list args) {
    int i;
    char *printed;

    // Use vsnprintf with a size of 0 to calculate the required length of the string
    i = vsnprintf(NULL, 0, fmt, args);
    if (i < 0) {
        return -1;
    }

    // Allocate memory (+1 for the null terminator)
    printed = (char *)malloc(i + 1);
    if (printed == NULL) {
        return -1;
    }
    
    // Actually print
    i = vsnprintf(printed, i + 1, fmt, args);
    if (i < 0) {
        free(printed);
        return -1;
    }
    
    *str = printed;
    return i;
}

int asprintf(char **str, const char *fmt, ...) {
    int i;
    va_list args;

    va_start(args, fmt);
    i = vasprintf(str, fmt, args);
    va_end(args);
    return i;
}
