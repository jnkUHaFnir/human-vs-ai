#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int custom_asprintf(char **strp, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Determine the required length
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (len < 0) {
        return -1;
    }

    // Allocate memory
    *strp = (char*) malloc(len + 1); // Add 1 for null terminator

    if (!*strp) {
        return -1;
    }

    va_start(args, format);
    vsnprintf(*strp, len + 1, format, args); // Write to allocated memory
    va_end(args);

    return len;
}

int main() {
    char *message;
    char result_code_string[] = "result_code";
    char result_string[] = "result_message";

    if (custom_asprintf(&message, "%s: %s", result_code_string, result_string) < 0) {
        fprintf(stderr, "Error in custom_asprintf\n");
        return 1;
    }

    printf("Message: %s\n", message);

    free(message);

    return 0;
}
