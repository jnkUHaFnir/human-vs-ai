#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceSubstring(const char *original, const char *pattern, const char *replacement) {
    if (original == NULL || pattern == NULL || replacement == NULL) {
        return NULL;
    }

    size_t patternLength = strlen(pattern);
    size_t replacementLength = strlen(replacement);

    // Count the number of occurrences of the pattern in the original string
    const char *tmp = original;
    size_t count = 0;
    while ((tmp = strstr(tmp, pattern))) {
        count++;
        tmp += patternLength;
    }

    // Allocate memory for the new string
    size_t resultLength = strlen(original) + count * (replacementLength - patternLength) + 1;
    char *result = (char *)malloc(resultLength);
    if (result == NULL) {
        return NULL;
    }

    // Replace the pattern with the replacement in the new string
    char *currentPosition = result;
    tmp = original;
    while (1) {
        const char *occurrence = strstr(tmp, pattern);
        if (occurrence == NULL) {
            strcpy(currentPosition, tmp);
            break;
        }

        ptrdiff_t charsToCopy = occurrence - tmp;
        strncpy(currentPosition, tmp, charsToCopy);
        currentPosition += charsToCopy;
        strcpy(currentPosition, replacement);
        currentPosition += replacementLength;
        tmp = occurrence + patternLength;
    }

    return result;
}

int main() {
    const char *original = "Hello, World! Hello, Universe!";
    const char *pattern = "Hello";
    const char *replacement = "Hi";

    char *result = replaceSubstring(original, pattern, replacement);
    if (result != NULL) {
        printf("Original: %s\n", original);
        printf("Replaced: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
