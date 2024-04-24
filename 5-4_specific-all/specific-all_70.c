#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int custom_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Get the size needed for the buffer
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, format, args_copy);
    va_end(args_copy);

    if (size < 0) {
        va_end(args);
        return -1;
    }

    // Allocate memory for the buffer
    *strp = (char *)malloc(size + 1); // +1 for null terminator

    if (*strp == NULL) {
        va_end(args);
        return -1;
    }

    // Create the string with the arguments
    vsnprintf(*strp, size + 1, format, args);

    va_end(args);

    return size;
}

int main() {
    char *message = NULL;
    int result_code = 200;
    char *result_string = "OK";

    if (custom_asprintf(&message, "%d: %s", result_code, result_string) >= 0) {
        // Use the message
        printf("%s\n", message);

        // Don't forget to free the allocated memory
        free(message);
    }

    return 0;
}
