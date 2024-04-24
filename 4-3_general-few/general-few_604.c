#include <stdio.h>
#include <string.h>

void replaceSubstring(char *string, const char *substring, const char *replacement) {
    char *p = string;
    int substringLen = strlen(substring);
    int replacementLen = strlen(replacement);
    while ((p = strstr(p, substring)) != NULL) {
        memmove(p + replacementLen, p + substringLen, strlen(p + substringLen) + 1);
        memcpy(p, replacement, replacementLen);
        p += replacementLen;
    }
}

int main() {
    char text[] = "hello world hello universe hello galaxy";
    char substring[] = "hello";
    char replacement[] = "hi";

    replaceSubstring(text, substring, replacement);

    printf("%s\n", text);

    return 0;
}
