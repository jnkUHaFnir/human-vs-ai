#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSubstring(char *originalString, const char *substring, const char *replacement) {
    char *result;
    char *temp;
    int replaceLen = strlen(replacement);
    int count = 0;
    int substringLen = strlen(substring);

    temp = originalString;
    while ((result = strstr(temp, substring)) != NULL) {
        count++;
        temp = result + substringLen;
    }

    int newSize = strlen(originalString) + count * (replaceLen - substringLen) + 1;
    char *newString = (char *) malloc(newSize);

    if (newString == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp = originalString;
    char *current;
    while ((result = strstr(temp, substring)) != NULL) {
        current = result - originalString + newString;
        strncat(newString, temp, result - temp);
        strcat(newString, replacement);
        temp = result + substringLen;
    }
    strcat(newString, temp);

    strcpy(originalString, newString);
    free(newString);
}

int main() {
    char str[] = "Hello, World! Hello, Universe!";
    char substring[] = "Hello";
    char replacement[] = "Hi";

    printf("Original string: %s\n", str);
    replaceSubstring(str, substring, replacement);
    printf("Modified string: %s\n", str);

    return 0;
}
