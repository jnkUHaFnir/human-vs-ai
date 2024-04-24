#include <stdio.h>
#include <stdarg.h>

int custom_asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // Determine the length of the formatted string
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (len < 0) {
        return -1; // Error in vsnprintf
    }

    // Allocate memory for the formatted string
    *strp = (char *)malloc(len + 1);
    if (!*strp) {
        return -1; // Error in memory allocation
    }

    va_start(args, fmt);
    vsnprintf(*strp, len + 1, fmt, args);
    va_end(args);

    return len;
}
