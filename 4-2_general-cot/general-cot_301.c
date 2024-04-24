#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null-terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    char* result = strdup(""); // Initialize with an empty string

    // .. build string out of variable-length data
    char str[20]; // Assuming a maximum string size of 20
    for (int i = 0; i < 5; i++) {
        sprintf(str, "%d", i); // Convert integer to string
        result = concat(result, str); // Perform concatenation
    }

    // .. some parts are conditional
    int freezeCount = -1; // Example value
    if (freezeCount < 0) {
        result = concat(result, "]");
    } else {
        result = concat(result, ")");
    }

    printf("Result: %s\n", result);

    free(result); // Free allocated memory

    return 0;
}
