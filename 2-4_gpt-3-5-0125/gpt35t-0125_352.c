#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <gc.h>

#define malloc(n)    GC_MALLOC(n)
#define calloc(m,n)  GC_MALLOC((m)*(n))
#define realloc(p,n) GC_REALLOC((p),(n))

typedef char * string;

int gc_asprintf(string *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    *str = calloc(sizeof(char), len + 1);
    if (*str == NULL) {
        return -1;
    }

    va_start(args, format);
    len = vsnprintf(*str, len + 1, format, args);
    va_end(args);

    return len;
}
