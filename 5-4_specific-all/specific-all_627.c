#include <stdio.h>
#include <string.h>

char* getcode(const char* input) {
    const char* p = input;
    char* buf;
    char* pbuf;

    if ((buf = malloc(256)) == NULL) {
        return NULL;
    }

    pbuf = buf;

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Skip "CODE="
            
            // Copy the value until '-' or end of the input
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            // Null-terminate the extracted code
            *pbuf = '\0';

            return buf;
        }

        p++;
    }

    // Clean up and return NULL if the pattern is not found
    free(buf);
    return NULL;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";

    char* extractedCode = getcode(buffer);

    if (extractedCode != NULL) {
        printf("Extracted Code: %s\n", extractedCode);
        free(extractedCode); // Don't forget to free the memory after use
    } else {
        printf("Code pattern not found\n");
    }

    return 0;
}
