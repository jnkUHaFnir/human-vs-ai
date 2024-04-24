#include <stdio.h>

#define REPEAT_CHAR(c, num) ({ \
    char buffer[(num) + 1]; \
    memset(buffer, (c), (num)); \
    buffer[num] = '\0'; \
    buffer; \
})

int main() {
    const char* repeatedStr = REPEAT_CHAR('-', 10);
    printf("%s\n", repeatedStr);
    return 0;
}
