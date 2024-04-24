#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getCode(const char* input) {
    const char* codePrefix = "CODE=";
    char* value = NULL;
    char* endPtr;
    size_t codeLength;
    
    // Find "CODE=" in the input string.
    char* startPtr = strstr(input, codePrefix);
    if (startPtr) {
        // Move past "CODE=" to the start of the value.
        startPtr += strlen(codePrefix);
        
        // Search for the next hyphen after "CODE=".
        endPtr = strchr(startPtr, '-');
        if (endPtr) {
            // Calculate the length of the code section.
            codeLength = endPtr - startPtr;
            
            // Allocate memory to hold the code section, plus a null terminator.
            value = malloc(codeLength + 1);
            if (!value) {
                // Memory allocation failed.
                return NULL;
            }
            
            // Copy the code section into the allocated memory.
            strncpy(value, startPtr, codeLength);
            value[codeLength] = '\0'; // null-terminate the string.
        }
    }
    
    // Return dynamically allocated string containing the code section or NULL.
    return value;
}

int main(void) {
    char buf[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* codeValue = getCode(buf);

    if (codeValue) {
        printf("Extracted value: '%s'\n", codeValue);
        free(codeValue); // Don't forget to free the allocated memory.
    } else {
        printf("No code value found.\n");
    }

    return 0;
}
