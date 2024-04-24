#ifndef _ASPRINTF_H
#define _ASPRINTF_H

#include <stdarg.h>
#include <stdlib.h>

int vasprintf(char **strp, const char *fmt, va_list ap);
int asprintf(char **strp, const char *fmt, ...);

#endif
#include "asprintf.h"

int vasprintf(char **strp, const char *fmt, va_list ap) {
    int len;

    va_list ap_copy;
    va_copy(ap_copy, ap);
    len = vsnprintf(NULL, 0, fmt, ap_copy);
    va_end(ap_copy);

    if (len < 0)
        return -1;

    char *buffer = malloc(len + 1);
    if (!buffer)
        return -1;

    int result = vsnprintf(buffer, len + 1, fmt, ap);
    if (result < 0) {
        free(buffer);
        return -1;
    }

    *strp = buffer;
    return result;
}

int asprintf(char **strp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vasprintf(strp, fmt, ap);
    va_end(ap);
    return result;
}
#include "asprintf.h"
