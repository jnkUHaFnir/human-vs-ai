#include <stdarg.h>
#include <stdlib.h>

int asprintf(char **strp, const char *fmt, ...)
{
    va_list args;
    char *buffer = NULL;
    int len;

    va_start(args, fmt);
    len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (len < 0) { /* vsnprintf failed */
        return -1;
    }

    /* +1 for the null terminating byte */
    buffer = (char*) malloc(len + 1); 
    if (buffer == NULL) { /* malloc failed */
        return -1;
    }

    va_start(args, fmt);
    len = vsnprintf(buffer, len + 1, fmt, args);
    va_end(args);

    if (len < 0) { /* vsnprintf failed */
        free(buffer);
        return -1;
    }

    *strp = buffer;
    return len;
}
