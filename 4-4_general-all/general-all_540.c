#include <stdio.h>

#define REPEAT_STRING(char, n) ({ \
    char str[(n) + 1]; \
    for (int i = 0; i < (n); i++) { \
        str[i] = (char); \
    } \
    str[(n)] = '\0'; \
    str; \
})

int main() {
    const char* repeatedString = REPEAT_STRING('-', 10);
    printf("%s\n", repeatedString);

    return 0;
}
