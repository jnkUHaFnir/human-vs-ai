#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    // Get the length needed by vsnprintf
    va_list args_copy;
    va_copy(args_copy, args);
    int len = vsnprintf(NULL, 0, fmt, args_copy) + 1; // +1 for null terminator
    va_end(args_copy);
    
    if (len <= 0) {
        va_end(args);
        return -1;
    }
    
    *strp = (char *)malloc(len);
    if (*strp == NULL) {
        va_end(args);
        return -1;
    }
    
    len = vsnprintf(*strp, len, fmt, args);
    
    va_end(args);
    
    return len;
}
#include "my_asprintf.h"

int main() {
    char *message = NULL;
    // Use my_asprintf as a replacement for asprintf
    my_asprintf(&message, "%.*s: %.*s",
                (int) result_code_string.length,
                (char *) result_code_string.data,
                (int) result_string.length,
                (char *) result_string.data);
    
    // After usage, remember to free the allocated memory
    free(message);

    return 0;
}
