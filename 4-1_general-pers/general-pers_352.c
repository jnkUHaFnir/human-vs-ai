#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gc.h>

#define asprintf_gc(ptr, fmt, ...) ({ \
    char *tmp_str = NULL; \
    int ret = asprintf(&tmp_str, fmt, __VA_ARGS); \
    if (ret != -1) { \
        *ptr = GC_STRDUP(tmp_str); \
        free(tmp_str); \
    } \
    ret; \
})

typedef char *string;

static string printInt(Object self) {
    string str = NULL;
    asprintf_gc(&str, "%lu", getValueInt(self));
    return str;
}
