#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int custom_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int length = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (length < 0) {
        return -1;
    }

    *strp = (char *)malloc(length + 1);
    if (!*strp) {
        return -1;
    }

    va_start(args, format);
    vsnprintf(*strp, length + 1, format, args);
    va_end(args);

    return length;
}
custom_asprintf(&message, "%.*s: %.*s",
      (int) result_code_string.length,
      (char *) result_code_string.data,
      (int) result_string.length,
      (char *) result_string.data);
