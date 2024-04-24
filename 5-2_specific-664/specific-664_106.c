#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Allocate memory for the concatenated string
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy the first string to the result
    memcpy(result, str1, len1);
    // Copy the second string to the result
    memcpy(result + len1, str2, len2 + 1); // +1 to include the null terminator

    return result;
}

int main() {
    char* result = concatenateStrings("Hello, ", "world!");

    if (result != NULL) {
        printf("Concatenated string: %s\n", result);
        free(result); // Free the dynamically allocated memory
    }

    return 0;
}
