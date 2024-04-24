#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Included for malloc

char* getcode(const char *input) {
    char *buf = (char*)malloc(256);
    if (buf == NULL) {
        return NULL;
    }

    char *p = (char*)input;
    char *pbuf = buf;

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Skip "CODE="
          
            // Copy the value until a '-' is found or reach the end of the string
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            // Add string terminator
            *pbuf = '\0';

            // Return the buffer with the extracted value
            return buf;
        }

        p++;
    }

    free(buf); // Free the allocated memory if CODE= is not found
    return NULL;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char *result = getcode(buffer);

    if (result != NULL) {
        printf("Found code: %s\n", result);
        free(result); // Free the allocated memory after using the result
    } else {
        printf("CODE= not found in the buffer\n");
    }

    return 0;
}
