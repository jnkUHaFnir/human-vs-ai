#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

char* concatenateStrings(char** strings, int length) {
    int totalSize = INITIAL_SIZE;
    char* result = (char*)malloc(totalSize * sizeof(char));
    result[0] = '\0'; // Initializing the result string

    for (int i = 0; i < length; i++) {
        int currentSize = strlen(result);
        int newSize = currentSize + strlen(strings[i]) + 1; // +1 for null terminator

        // Check if we need to reallocate memory
        if (newSize > totalSize) {
            totalSize = newSize * 2;
            result = (char*)realloc(result, totalSize * sizeof(char));
        }

        // Concatenate the current string
        strcat(result, strings[i]);
    }

    return result;
}

int main() {
    char* strings[] = {"Hello, ", "world", "!", " This is a test."};
    int length = sizeof(strings) / sizeof(strings[0]);

    char* concatenated = concatenateStrings(strings, length);
    printf("Concatenated string: %s\n", concatenated);

    free(concatenated); // Don't forget to free the dynamically allocated memory

    return 0;
}
