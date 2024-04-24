#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char *src = NULL;
    int totalLength = 0; // Initialize total length

    unsigned char *tmp;
    int length = (parameterArray[i].sizeInBits/8) + 1;
    tmp = (unsigned char*)malloc(length); // Use malloc to allocate memory for tmp

    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

    // Calculate total length needed for realloc
    int tmpLength = strlen(tmp);
    totalLength += tmpLength;

    src = (unsigned char*)realloc(src, totalLength + 1); // +1 for null terminator
    if (src == NULL) {
        fprintf(stderr, "Error reallocating memory\n");
        exit(1);
    }

    memcpy(src + totalLength - tmpLength, tmp, tmpLength); // Copy tmp to src

    // Add null terminator
    src[totalLength] = '\0';

    // Printing the result just as an example
    printf("Merged String: %s\n", src);

    free(tmp); // Free the memory allocated for tmp
    free(src); // Don't forget to free the memory allocated for src

    return 0;
}
