#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 100

char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*)malloc(len1 + len2 + 1); // +1 for null terminator

    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    char* result = (char*)malloc(INITIAL_SIZE);
    size_t totalLength = 0;
    strcpy(result, "");

    // Build string out of variable-length data
    for (int i = 0; i < variableLength; i++) {
        char* objectString = getObjectAsString(); // Function to get object as string
        char* temp = concatenateStrings(result, objectString);

        // Check for memory allocation failure
        if (temp == NULL) {
            // Handle memory allocation failure
            free(result);
            return 1;
        }

        free(result);
        result = temp;
    }

    // Some parts are conditional
    char* conditionalStr = (freezeCount < 0) ? "]" : ")";
    char* finalResult = concatenateStrings(result, conditionalStr);

    if (finalResult == NULL) {
        // Handle memory allocation failure
        free(result);
        return 1;
    }

    printf("Final Result: %s\n", finalResult);

    // Clean up
    free(result);
    free(finalResult);

    return 0;
}
