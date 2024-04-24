#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include stdlib.h for malloc

char* getcode(const char* input) {
    char* buf;
    const char* p = input;
    
    buf = (char*)malloc(255); // Allocate memory for buf

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Move past "CODE="
            
            while (*p && *p != '-' && isdigit(*p)) {
                *buf++ = *p++;
            }
            break; // Stop after capturing the code part
        }
        p++;
    }
    *buf = '\0'; // Add null terminator to the end of buf

    return buf;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* result = getcode(buffer);
    
    if (result) {
        printf("Found code: %s\n", result);
        free(result); // Free allocated memory when done using it
    } else {
        printf("Code not found.\n");
    }

    return 0;
}
