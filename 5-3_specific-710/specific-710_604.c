#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find and replace all occurrences of a substring in a string
char *findAndReplaceAll(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int subLen = strlen(sub);
    int replaceLen = strlen(replace);

    // Calculate the size of the final string, taking into account the length of the replacement string
    int resultLen = strlen(str) + 1; // +1 for null terminator
    int count = 0;
    const char *ptr = str;
    while ((ptr = strstr(ptr, sub)) != NULL) {
        count++;
        ptr += subLen;
    }
    resultLen += count * (replaceLen - subLen);

    char *result = malloc(resultLen);
    if (!result) {
        return NULL;
    }

    // Perform the find and replace
    char *dest = result;
    const char *src = str;
    while (*src) {
        if (strstr(src, sub) == src) {
            strcpy(dest, replace);
            dest += replaceLen;
            src += subLen;
        } else {
            *dest++ = *src++;
        }
    }
    *dest = '\0';

    return result;
}

int main() {
    const char *str = "hello world, hello universe, hello galaxy";
    const char *sub = "hello";
    const char *replace = "hi";

    char *result = findAndReplaceAll(str, sub, replace);
    if (result) {
        printf("Original string: %s\n", str);
        printf("After replacement: %s\n", result);
        free(result);
    }

    return 0;
}
