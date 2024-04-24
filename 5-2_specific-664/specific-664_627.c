#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* getcode(const char *input)
{
    char *p = (char*)input;
    char *buf;
    char *pbuf;

    if ((buf = (char*)malloc(256)) == NULL)
        return NULL;

    pbuf = buf;

    while (*p != '\0') {
        if (strncmp(p, "CODE=", 5) == 0) {
            p += 5; // move past "CODE="

            // copy the value until a '-' is found
            while (*p != '\0' && *p != '-') {
                *pbuf++ = *p++;
            }

            break; // stop after finding the first occurrence
        }

        p++;
    }

    *pbuf = '\0'; // add null terminator

    return buf;
}

int main()
{
    char buffer[255] = "CODE=12345-MODE-12453-CODE1-12355";
    char* code = getcode(buffer);

    if (code != NULL) {
        printf("Found code: %s\n", code);
        free(code); // don't forget to free the allocated memory
    } else {
        printf("Code not found\n");
    }

    return 0;
}
