#include <stdio.h>

#define REPEAT_STRING(character, length) ( \
    { \
        char str[length + 1]; \
        for (int i = 0; i < length; i++) { \
            str[i] = character; \
        } \
        str[length] = '\0'; \
        str; \
    } \
)

int main() {
    const char* repeatedString = REPEAT_STRING('-', 10);
    printf("%s\n", repeatedString);

    return 0;
}
----------
