#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int custom_asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    // Get the length of the formatted string
    int size = vsnprintf(NULL, 0, fmt, args);
    if (size < 0) {
        va_end(args);
        return -1;
    }

    // Allocate memory for the string
    *strp = (char *)malloc(size + 1);
    if (*strp == NULL) {
        va_end(args);
        return -1;
    }

    // Write the formatted string to the allocated memory
    vsnprintf(*strp, size + 1, fmt, args);

    va_end(args);
    
    return size;
}
char *message = NULL;
int ret = custom_asprintf(&message, "%.*s: %.*s",
                          (int) result_code_string.length,
                          (char *) result_code_string.data,
                          (int) result_string.length,
                          (char *) result_string.data);

if (ret < 0) {
    // Handle error (e.g., memory allocation failure)
} else {
    // Use the formatted string stored in `message`
    // Don't forget to free the allocated memory when you are done with `message`
    free(message);
}
