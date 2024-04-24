#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* getcode(const char *input);

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* result = getcode(buffer);

    if (result != NULL) {
        printf("Found code: %s\n", result);
        free(result); // Free the dynamically allocated memory after using it
    } else {
        printf("Code not found\n");
    }

    return 0;
}

char* getcode(const char *input) {
    const char* p = input;
    char* buf = (char*)malloc(256);
    char* pbuf = buf;

    if (buf == NULL) {
        return NULL;
    }

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Move past 'CODE='

            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            break;
        }
        p++;
    }

    *pbuf = '\0'; // Null-terminate the string

    return buf;
}
