#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

int main() {
    unsigned char *src = malloc(INITIAL_SIZE); // Allocate initial space for src
    if (src == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    size_t src_len = 0;
    
    unsigned char *tmp;
    int length = (parameterArray[i].sizeInBits/8) + 1;
    tmp = malloc(length); // Allocate memory for temp array
    if (tmp == NULL) {
        printf("Memory allocation failed\n");
        free(src);
        return 1;
    }

    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

    // Reallocate space for total string
    src = realloc(src, src_len + length + 1); // +1 for the null terminator
    if (src == NULL) {
        printf("Memory reallocation failed\n");
        free(tmp);
        free(src);
        return 1;
    }

    strncat(src, tmp, length);
    src_len += length;
    
    printf("Merged string: %s\n", src);

    free(tmp);
    free(src);
    
    return 0;
}
