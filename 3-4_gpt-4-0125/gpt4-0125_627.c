#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getcode(const char *input) {
    const char* codeToken = "CODE=";
    char *codeValue = NULL;
    int i, codeValueLength = 0;

    char *start = strstr(input, codeToken);
    if (start != NULL) {
        // Skip past "CODE="
        start += strlen(codeToken);

        // Calculate the length until the next '-' or end of the string
        for (i = 0; start[i] != '-' && start[i] != '\0'; i++);
        codeValueLength = i;

        // Allocate memory for the code value
        codeValue = (char*)malloc(codeValueLength + 1); // +1 for '\0'
        if (codeValue == NULL) {
            // Memory allocation failed
            return NULL;
        }

        // Copy the code
        strncpy(codeValue, start, codeValueLength);
        // Null terminate the string
        codeValue[codeValueLength] = '\0';
    }

    return codeValue; // Remember to free this memory in the calling function!
}

int main () {
    char buf[255]="CODE=12345-MODE-12453-CODE1-12355";
    char *code = getcode(buf);

    if (code != NULL) {
        printf("Extracted value: %s\n", code);
        free(code); // Free the allocated memory!
    } else {
        printf("CODE= not found or an error occurred.\n");
    }

    return 0;
}
