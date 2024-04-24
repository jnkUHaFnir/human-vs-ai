#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int custom_asprintf(char **str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    // Determine the size needed for the string
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    // Allocate memory for the string
    *str = (char*)malloc(size + 1);
    if (*str == NULL) {
        return -1;
    }

    // Write the formatted string to the allocated memory
    int ret = vsnprintf(*str, size + 1, format, args);

    va_end(args);

    return ret;
}
custom_asprintf(&message, "%.*s: %.*s",
          (int) result_code_string.length,
          (char *) result_code_string.data,
          (int) result_string.length,
          (char *) result_string.data);
