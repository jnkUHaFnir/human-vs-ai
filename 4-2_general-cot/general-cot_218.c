#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Parameter {
    int sizeInBits;
    unsigned char valueU8;
};

int main() {
    unsigned char *src = NULL; // Initialize src
    struct Parameter parameterArray[ARRAY_SIZE]; // Assuming this array is defined elsewhere
    int i = 0;

    int length = (parameterArray[i].sizeInBits / 8) + 1;
    unsigned char tmp[length];
    
    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

    src = (unsigned char*)realloc(src, (src ? strlen((char*)src) : 0) + strlen((char*)tmp) + 1); // +1 for null terminator
    if (src == NULL) {
        fprintf(stderr, "Memory reallocation failed.\n");
        exit(1);
    }

    strncat((char*)src, (char*)tmp, strlen((char*)tmp));
    
    printf("%s\n", src); // Just an example to show the merged string
    
    // Don't forget to free the memory at the end
    free(src);

    return 0;
}
