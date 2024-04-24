#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find and replace all occurrences of a substring in a string
char *replaceSubstr(const char *string, const char *substr, const char *replace) {
    char *result;
    int i, count = 0;
    int newLen, oldLen = strlen(substr);

    // Count the number of occurrences of substring
    for (i = 0; string[i] != '\0'; i++) {
        if (strstr(&string[i], substr) == &string[i]) {
            count++;
            i += oldLen - 1;
        }
    }

    // Allocate memory for the new string
    newLen = strlen(string) + count * (strlen(replace) - oldLen) + 1;
    result = (char *)malloc(newLen);

    i = 0;
    while (*string) {
        // Check if the substring is found
        if (strstr(string, substr) == string) {
            strcpy(&result[i], replace);
            i += strlen(replace);
            string += oldLen;
        } else {
            result[i++] = *string++;
        }
    }
    result[i] = '\0';

    return result;
}

int main() {
    const char *original = "Hello, how are you?";
    const char *substring = "you";
    const char *replacement = "I";

    char *result = replaceSubstr(original, substring, replacement);

    printf("Original: %s\n", original);
    printf("After replacement: %s\n", result);

    // Don't forget to free the dynamically allocated memory
    free(result);

    return 0;
}
