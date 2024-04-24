#include <stdio.h>
#include <string.h>
#include <ctype.h> // for isspace
#include <stdlib.h> // for malloc

#define MAX_BUFFER_SIZE 255

char* getcode(const char *input) {
    char *p = (char*) input, *buf, *pbuf;

    if((buf = malloc(MAX_BUFFER_SIZE)) == NULL)
        return NULL;

    pbuf = buf;
    
    while(*p != '\0') {
        if(strncmp(p, "CODE=", 5) == 0) {
            p += 5; // skip 'CODE='
            
            while(*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }
            
            *pbuf = '\0'; // terminate string
            break;
        }
        p++;
    }

    return buf;
}

int main() {
    char buffer[MAX_BUFFER_SIZE] = "CODE=12345-MODE-12453-CODE1-12355";
    char *foundCode = getcode(buffer);

    if(foundCode) {
        printf("Found code: %s\n", foundCode);
        free(foundCode); // don't forget to free the allocated memory
    } else {
        printf("Code not found\n");
    }

    return 0;
}
