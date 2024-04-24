#include <stdio.h>
#include <gc.h>

int my_asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int size = vasprintf(strp, fmt, args);

    va_end(args);

    if (size != -1) {
        // Reallocate memory using GC_MALLOC
        char *gc_str = (char *)GC_MALLOC(size + 1);
        if (gc_str != NULL) {
            strcpy(gc_str, *strp);
            *strp = gc_str;
            return size;
        } else {
            // Handle allocation failure
            free(*strp);
            *strp = NULL;
            return -1;
        }
    } else {
        // Handle vasprintf failure
        *strp = NULL;
        return -1;
    }
}

// Usage example
static string printInt(Object self) {
    string str = NULL;
    my_asprintf(&str, "%lu", getValueInt(self));
    return str;
}
