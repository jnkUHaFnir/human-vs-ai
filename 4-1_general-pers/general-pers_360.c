#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getcode(const char *input) {
    const char* p = input;
    char* code = NULL;
    char* codeValue = NULL;

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Move past "CODE="
            const char* start = p; // Start of the code value
            while (*p != '\0' && *p != '-') {
                p++;
            }
            size_t length = p - start;
            code = (char*)malloc(length + 1); // Allocate memory for code
            if (code == NULL) {
                return NULL; // Memory allocation failed
            }
            strncpy(code, start, length); // Copy code to allocated memory
            code[length] = '\0'; // Null-terminate the string
            codeValue = code; // Set codeValue to the extracted code
            break; // Exit the loop after extracting the first "CODE=" value
        }
        p++;
    }

    return codeValue;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* extractedCode = getcode(buffer);

    if (extractedCode != NULL) {
        printf("Extracted CODE value: %s\n", extractedCode);
        free(extractedCode); // Remember to free the allocated memory
    } else {
        printf("CODE value not found\n");
    }

    return 0;
}
