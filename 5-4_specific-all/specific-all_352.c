#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gc.h>

#define asprintf(buf, fmt, ...) do { \
    char *tmp; \
    if (asprintf(&tmp, fmt, ##__VA_ARGS__) == -1) { \
        *(buf) = NULL; \
    } else { \
        size_t len = strlen(tmp); \
        *(buf) = GC_MALLOC(len + 1); \
        if (*(buf) != NULL) { \
            strcpy(*(buf), tmp); \
        } \
        free(tmp); \
    } \
} while (0)

typedef char *string;

static string printInt(Object self) {
    string str;
    asprintf(&str, "%lu", getValueInt(self));
    return str;
}
