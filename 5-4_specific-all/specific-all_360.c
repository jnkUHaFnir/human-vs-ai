#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getcode(const char *input) {
    char *p = (char*) input, *buf, *pbuf;

    if((buf = malloc(255)) == NULL) 
        return NULL;

    pbuf = buf;
    while(*p != '\0') {
        if(strncmp(p, "CODE=", 5) == 0) {
            p += 5; // move past 'CODE='

            // copy the value until found a '-'
            while(*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            // put 0-terminator
            *pbuf = '\0';
            break;
        }
        p++;
    }

    return buf;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char *code = getcode(buffer);

    if (code != NULL) {
        printf("Found code: %s\n", code);
        free(code); // Free the memory allocated for the code
    } else {
        printf("Code not found\n");
    }

    return 0;
}
