#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getcode(const char *input) {
    char *code = NULL;
    const char* p = input;

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Skip "CODE="
            const char* end = strchr(p, '-');  // Find the next '-'

            if (end == NULL) {  // If '-' is not found, handle it based on the end of the string
                end = p + strlen(p);
            }

            size_t code_len = end - p; // Calculate the length of the code
            code = (char*)malloc(code_len + 1);  // Allocate memory for the code
            strncpy(code, p, code_len);  // Copy the code
            code[code_len] = '\0';  // Null-terminate the code
            break;  // Exit the loop after finding the first occurrence
        }
        p++;
    }

    return code;  // Return the extracted code
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* code = getcode(buffer);

    if (code != NULL) {
        printf("Extracted code: %s\n", code);
        free(code);  // Free the memory allocated for code
    } else {
        printf("Code not found\n");
    }

    return 0;
}
