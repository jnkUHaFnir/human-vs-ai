#include <stdio.h>

#define REPEAT_STRING(str, count) ({ \
    char* repeated = malloc(strlen(str) * count + 1); \
    repeated[0] = '\0'; \
    for (int i = 0; i < count; i++) { \
        strcat(repeated, str); \
    } \
    repeated; \
})

int main() {
    char* repeatedString = REPEAT_STRING("-", 10);
    printf("%s\n", repeatedString);
    free(repeatedString); // Don't forget to free the allocated memory
    return 0;
}
