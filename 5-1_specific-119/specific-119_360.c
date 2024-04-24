#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TRIMSPACES(p) while(*p != '\0' && isspace((unsigned char)*p) != 0) ++p
#define NSTRIP(p, n) p += n
#define STRIP(p) ++p

char* getcode(const char *input) {
    char *p = (char*) input, *buf, *pbuf;

    if((buf = malloc(256)) == NULL)
        return NULL;

    pbuf = buf;
    while(*p != '\0') {
        if(strncmp(p, "CODE", 4) == 0) {
            p += 4; // remove 'CODE'
            TRIMSPACES(p); // trim white-space after 'CODE'

            if(*p != '=')
                return NULL;

            p++; // remove '='
            TRIMSPACES(p); // trim white-spaces after '='

            while(*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }
            *pbuf++ = '\0';
            break;
        }
        p++;
    }

    return buf;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* code = getcode(buffer);

    if(code != NULL) {
        printf("Found code: %s\n", code);
        free(code);
    } else {
        printf("Code not found.\n");
    }

    return 0;
}
