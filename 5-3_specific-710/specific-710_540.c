#include <stdio.h>
#include <string.h>

#define REPEAT_STRING(s, n) ({ \
    const char* str = s; \
    size_t len = strlen(str); \
    size_t times = n; \
    size_t total_len = len * times; \
    char* result = (char*)malloc(total_len + 1); \
    if (result) { \
        for (size_t i = 0; i < times; i++) { \
            memcpy(result + i * len, str, len); \
        } \
        result[total_len] = '\0'; \
    } \
    result; \
})

int main() {
    const char* repeated = REPEAT_STRING("-", 10);
    printf("%s\n", repeated);

    free((void*)repeated); // Don't forget to free the allocated memory
    return 0;
}
