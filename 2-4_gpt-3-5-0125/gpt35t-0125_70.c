#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Determine the required size
    int size = vsnprintf(NULL, 0, format, args);
    if (size < 0) {
        va_end(args);
        return -1;
    }

    // Allocate memory for the string
    *strp = malloc(size + 1);
    if (*strp == NULL) {
        va_end(args);
        return -1;
    }

    // Copy the formatted string to the allocated memory
    vsnprintf(*strp, size + 1, format, args);

    va_end(args);
    return size;
}
my_asprintf(&message, "%.*s: %.*s",
          (int) result_code_string.length,
          (char *) result_code_string.data,
          (int) result_string.length,
          (char *) result_string.data);
free(message);
