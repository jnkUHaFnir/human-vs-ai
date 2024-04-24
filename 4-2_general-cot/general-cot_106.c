#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenateStrings(const char* objStrings[], int count, int freezeCount) {
    size_t totalLength = 0;
    for (int i = 0; i < count; i++) {
        totalLength += strlen(objStrings[i]);
    }
    
    char *result = (char *)malloc(totalLength + 1); // +1 for null terminator
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    size_t pos = 0;
    for (int i = 0; i < count; i++) {
        strcpy(result + pos, objStrings[i]);
        pos += strlen(objStrings[i]);
    }

    if (freezeCount < 0) {
        strcat(result, "]");
    } else {
        strcat(result, ")");
    }

    return result;
}

int main() {
    const char* objStrings[] = {"string1", "string2", "string3"};
    int count = 3;
    int freezeCount = 1;

    char *result = concatenateStrings(objStrings, count, freezeCount);
    printf("Resulting string: %s\n", result);

    free(result); // Don't forget to free the allocated memory
    return 0;
}
