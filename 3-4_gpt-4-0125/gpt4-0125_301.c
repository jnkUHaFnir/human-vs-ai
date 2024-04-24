#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* appendStr(char *dest, const char *src) {
    size_t destLen = dest ? strlen(dest) : 0;
    size_t srcLen = strlen(src);

    // Reallocate, adding space for the new string + '\0'
    dest = realloc(dest, destLen + srcLen + 1);

    if (dest == NULL) {
        perror("Failed to reallocate memory");
        exit(EXIT_FAILURE);
    }

    // Copy/append the new string
    strcpy(dest + destLen, src);

    return dest;
}

int main() {
    char *result = NULL;  // Start with NULL so the realloc in appendStr works correctly.

    // Example usage:
    result = appendStr(result, "Hello");
    result = appendStr(result, ", ");
    result = appendStr(result, "world!");

    // Conditionally append more strings
    int freezeCount = -1;
    if (freezeCount < 0) result = appendStr(result, "]");
    else result = appendStr(result, ")");

    printf("%s\n", result);

    // Clean up
    free(result);

    return 0;
}
