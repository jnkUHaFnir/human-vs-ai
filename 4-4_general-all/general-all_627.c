#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* get_code(const char *input) {
    const char *p = input;
    char *buf = (char*) malloc(255); // Allocate memory for the buffer
    if (buf == NULL) {
        return NULL; // Memory allocation failed
    }

    char *pbuf = buf;
    
    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Move past "CODE="
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++; // Copy characters until '-'
            }
            break; // Exit after processing the CODE value
        }
        p++;
    }

    *pbuf = '\0'; // Add null terminator to the end
    return buf;
}

int main() {
    char buf[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* code = get_code(buf);

    if (code != NULL) {
        printf("Found CODE: %s\n", code);
        free(code); // Free the allocated memory
    } else {
        printf("CODE not found.\n");
    }

    return 0;
}
