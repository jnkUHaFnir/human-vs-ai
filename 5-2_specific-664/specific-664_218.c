#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *src = NULL; // initialize src to NULL

// Assuming parameterArray is defined somewhere

int main() {
    unsigned char *src;
    
    int length = (parameterArray[i].sizeInBits / 8) + 1;
    unsigned char tmp[length];

    memcpy(tmp, &parameterArray[i].valueU8, length);

    // Calculate total length required for src
    size_t newLength = (src ? strlen(src) : 0) + strlen(tmp) + 1;

    src = realloc(src, newLength); // reallocate space for total string

    if (src == NULL) {
        fprintf(stderr, "Memory reallocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    strncat(src, tmp, strlen(tmp)); // merge

    // Make sure src is null terminated
    src[newLength - 1] = '\0';

    // Use src as needed

    return 0;
}
