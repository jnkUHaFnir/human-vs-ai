#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isspace()
#include <stdlib.h> // Include stdlib.h for malloc()

char* getcode(const char *input) {
    const char *p = input;
    char *buf, *pbuf;

    if ((buf = (char*)malloc(256)) == NULL) {
        return NULL;
    }

    pbuf = buf;
    while (*p != '\0') {
        if (strncmp(p, "CODE", 4) == 0) {
            p += 4; // Move past "CODE"
            while (*p != '\0' && *p != '=' && isspace((unsigned char)*p)) {
                p++; // Skip whitespace and '='
            }

            if (*p != '=') {
                free(buf); // Free allocated memory in case of failure
                return NULL;
            }

            p++; // Move past '='
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            // Add null terminator
            *pbuf = '\0';

            return buf;
        }
        p++;
    }

    free(buf); // Free allocated memory if pattern not found
    return NULL;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* result = getcode(buffer);

    if (result != NULL) {
        printf("Found pattern: %s\n", result);
        free(result); // Free memory allocated by getcode()
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}
