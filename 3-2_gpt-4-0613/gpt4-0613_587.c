#include <stdlib.h>
#include <errno.h>
#include <string.h>

int parse4Hex(const char *str, size_t offset) {
    char hexBuffer[5]; 
    long result;
    char *endptr;

    if (strlen(str) < offset + 4) {
        fprintf(stderr, "Not enough chars in input string\n"); 
        return -1;
    }

    strncpy(hexBuffer, &str[offset], 4); 
    hexBuffer[4] = '\0'; 

    errno = 0; 
    result = strtol(hexBuffer, &endptr, 16);

    if (endptr == hexBuffer) {
        fprintf(stderr, "No digits were found\n"); 
        return -1;
    }

    if (errno == ERANGE) {
        fprintf(stderr, "Integer overflow\n"); 
        return -1;
    }

    if (errno != 0 && result == 0) {
        fprintf(stderr, "Other errors\n"); 
        return -1;
    }

    return (int) result;
}
