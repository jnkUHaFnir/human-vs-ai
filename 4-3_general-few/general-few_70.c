#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int my_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    if (count < 0) {
        return -1;
    }
    
    *strp = (char *)malloc(count + 1);
    if (*strp == NULL) {
        return -1;
    }
    
    va_start(args, format);
    count = vsnprintf(*strp, count + 1, format, args);
    va_end(args);
    
    return count;
}
my_asprintf(&message, "%.*s: %.*s",
          (int) result_code_string.length,
          (char *) result_code_string.data,
          (int) result_string.length,
          (char *) result_string.data);
