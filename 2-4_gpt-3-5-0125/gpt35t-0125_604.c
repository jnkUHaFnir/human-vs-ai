#include <stdio.h>
#include <string.h>

char *replaceSubstring(const char *str, const char *sub, const char *replace) {
    char *result;
    int i, count = 0;
    int sublen = strlen(sub);
    int replen = strlen(replace);

    // Count how many times the substring appears in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], sub) == &str[i]) {
            count++;
            i += sublen - 1;
        }
    }

    // Allocate memory for the new string
    result = (char *)malloc(strlen(str) + count * (replen - sublen) + 1);

    i = 0;
    while (*str) {
        // Check if the substring is at the current position
        if (strstr(str, sub) == str) {
            strcpy(&result[i], replace);
            i += replen;
            str += sublen;
        } else {
            result[i++] = *str++;
        }
    }
    result[i] = '\0';

    return result;
}

int main() {
    char str[] = "hello world hello hello";
    char sub[] = "hello";
    char replace[] = "hi";

    char *newStr = replaceSubstring(str, sub, replace);

    printf("Original string: %s\n", str);
    printf("New string: %s\n", newStr);

    free(newStr);

    return 0;
}
