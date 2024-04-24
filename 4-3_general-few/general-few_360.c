#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isspace
#include <stdlib.h> // Include stdlib.h for malloc

char* getcode(const char *input) {
    char *p = (char*)input;
    char *buf, *pbuf;

    if ((buf = malloc(256)) == NULL) {
        return NULL;
    }

    pbuf = buf;
    while (*p != '\0') {
        if(strncmp(p, "CODE=", 5) == 0) {
            p += 5; // Move past "CODE="
            
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            break;
        } else {
            p++;
        }
    }

    *pbuf = '\0'; // Null-terminate the code

    return buf;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* result = getcode(buffer);
    
    if (result != NULL) {
        printf("Code found: %s\n", result);
        free(result); // Don't forget to free memory allocated by malloc
    } else {
        printf("Code not found\n");
    }

    return 0;
}
