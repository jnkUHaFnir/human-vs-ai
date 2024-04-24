#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRIMSPACES(p) while (*p != '\0' && isspace((unsigned char)*p)) ++p
#define NSTRIP(p, n) p += n
#define STRIP(p) ++p

char* getcode(const char *input) {
    char *p = (char*) input, *buf, *pbuf;

    if ((buf = malloc(256)) == NULL)
        return NULL;

    pbuf = buf;
    while (*p != '\0') {
        if (strncmp(p, "CODE", 4) == 0) {
            NSTRIP(p, 4); // remove 'CODE'
            TRIMSPACES(p); // trim white-space after 'CODE'

            if (*p != '=')  
                return NULL;

            STRIP(p); // remove '='
            TRIMSPACES(p); // trim white-spaces after '='

            // copy the value until a '-' is found
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }
            break;
        }
        p++;
    }

    // put 0-terminator.
    *pbuf = '\0';

    return buf;
}

int main() {
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char *code = getcode(buffer);

    if (code == NULL) {
        printf("Code not found.\n");
    } else {
        printf("Code: %s\n", code);
        free(code);
    }

    return 0;
}
