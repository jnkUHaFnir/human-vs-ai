#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <gc.h>

#define asprintf(buf, format, ...) do { \
    char* tmp; \
    if (asprintf(&tmp, format, ##__VA_ARGS__) == -1) { \
        *(buf) = NULL; \
    } else { \
        *(buf) = GC_STRDUP(tmp); \
        free(tmp); \
    } \
} while (0)

typedef char* string;

static string printInt(Object self) {
    string str;
    asprintf(&str, "%lu", getValueInt(self));
    return str;
}
