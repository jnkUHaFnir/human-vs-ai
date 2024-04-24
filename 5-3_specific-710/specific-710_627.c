#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getcode(const char *input) {
    const char* target = "CODE=";
    const size_t targetLen = strlen(target);

    const char* p = input;
    char* result = NULL;
    
    while ((p = strstr(p, target)) != NULL) {
        p += targetLen; // Move past the "CODE=" part
        
        const char* end = strchr(p, '-'); // Find the end marker
        
        if (end == NULL) {
            end = p + strlen(p); // If there's no '-', set end to end of string
        }
        
        size_t codeLen = end - p; // Calculate the length of the code
        
        if (codeLen > 0) {
            result = (char*)malloc(codeLen + 1); // Allocate memory for code + null terminator
            if (result == NULL) {
                return NULL; // Return NULL on allocation failure
            }
            
            strncpy(result, p, codeLen); // Copy the code to result
            result[codeLen] = '\0'; // Null-terminate the result
            break; // Break after finding the first occurrence
        }
        
        p = end; // Move to the next part in the buffer
    }
    
    return result;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    
    char* code = getcode(buffer);
    
    if (code != NULL) {
        printf("Found code: %s\n", code);
        free(code);
    } else {
        printf("Code not found\n");
    }
    
    return 0;
}
