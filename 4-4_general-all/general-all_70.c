#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Determine the length of the formatted string
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    // Allocate memory for the formatted string
    *strp = (char *)malloc(size + 1);
    if (*strp == NULL) {
        return -1; // Allocation failed
    }

    // Populate the allocated string with the formatted content
    vsnprintf(*strp, size + 1, format, args);

    va_end(args);

    return size;
}
// Include the my_asprintf function
int my_asprintf(char **strp, const char *format, ...);
char *message;
my_asprintf(&message, "%.*s: %.*s",
             (int) result_code_string.length,
             (char *) result_code_string.data,
             (int) result_string.length,
             (char *) result_string.data);
