#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char *src = NULL; // Initialize src to NULL
    int length = (parameterArray[i].sizeInBits/8) + 1;
    unsigned char tmp[length];

    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);
    
    // Properly allocate memory for src
    if(src == NULL) {
        src = malloc(strlen(tmp) + 1); // +1 for null terminator
        if(src == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            exit(1);
        }
        strcpy(src, "");
    }

    src = realloc(src, strlen(src) + strlen(tmp) + 1); // +1 for null terminator
    if(src == NULL) {
        printf("Memory reallocation failed. Exiting.\n");
        exit(1);
    }

    strncat(src, tmp, strlen(tmp));
    
    // Use src for whatever purpose you need
    printf("Concatenated string: %s\n", src);
    
    free(src); // Don't forget to free allocated memory

    return 0;
}
