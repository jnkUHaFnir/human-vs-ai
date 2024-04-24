#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSubstring(char *string, const char *substring, const char *replacement) {
    int substringLen = strlen(substring);
    int replacementLen = strlen(replacement);

    char *occurrence = string;
    while((occurrence = strstr(occurrence, substring))) {
        memmove(occurrence + replacementLen, occurrence + substringLen, strlen(occurrence + substringLen) + 1);
        memcpy(occurrence, replacement, replacementLen);
        occurrence += replacementLen;
    }
}

int main() {
    char str[] = "This is a test string with test substring.";
    const char *substring = "test";
    const char *replacement = "example";

    printf("Before: %s\n", str);
    replaceSubstring(str, substring, replacement);
    printf("After: %s\n", str);

    return 0;
}
