#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceSubstring(const char* original, const char* pattern, const char* replacement) {
    size_t patternLen = strlen(pattern);
    size_t replacementLen = strlen(replacement);
    size_t count = 0;

    // Count occurrences of pattern in original
    const char* tmp = original;
    while ((tmp = strstr(tmp, pattern))) {
        count++;
        tmp += patternLen;
    }

    // Calculate new string length
    size_t newLen = strlen(original) + count * (replacementLen - patternLen);
    char* result = malloc(newLen + 1); // +1 for null terminator
    if (!result) return NULL; // Check for malloc failure

    const char* currentPos = original;
    char* resultPos = result;

    // Replace each occurrence
    while ((tmp = strstr(currentPos, pattern))) {
        // Copy part before pattern
        size_t bytesToCopy = tmp - currentPos;
        memcpy(resultPos, currentPos, bytesToCopy);
        resultPos += bytesToCopy;

        // Copy replacement
        memcpy(resultPos, replacement, replacementLen);
        resultPos += replacementLen;

        // Move past last occurrence of pattern
        currentPos = tmp + patternLen;
    }

    // Copy the remaining part of original string
    strcpy(resultPos, currentPos);

    return result;
}

int main() {
    const char* originalString = "Hello world, world is wonderful!";
    const char* pattern = "world";
    const char* replacement = "universe";

    char* result = replaceSubstring(originalString, pattern, replacement);
    if (result) {
        printf("Original: %s\n", originalString);
        printf("Replaced: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}
