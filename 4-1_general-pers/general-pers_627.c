#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* getcode(const char *input) {
    const char* keyword = "CODE=";
    char *code = NULL;
    size_t keyword_len = strlen(keyword);
    const char* p = input;

    while (*p != '\0') {
        if (strncmp(p, keyword, keyword_len) == 0) {
            p += keyword_len; // move pointer past "CODE="
            const char* start = p;
            
            // Find end of the code section
            while (*p != '\0' && (*p != '-' && !isspace(*p))) {
                p++;
            }

            // Calculate the length and allocate memory for the code section
            size_t code_len = p - start;
            code = (char*)malloc(code_len + 1); // +1 for null-terminator
            if (code == NULL) {
                // Handle memory allocation failure
                return NULL;
            }

            // Copy the code section
            strncpy(code, start, code_len);
            code[code_len] = '\0'; // Null-terminate the string
            break; // Stop searching after finding the first occurrence
        }
        p++;
    }

    return code;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* code = getcode(buffer);

    if (code != NULL) {
        printf("Found code: %s\n", code);
        free(code); // Free allocated memory
    } else {
        printf("Code not found.\n");
    }

    return 0;
}
