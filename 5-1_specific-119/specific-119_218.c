#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char *src = NULL; // Initialize src to NULL
    int length = (parameterArray[i].sizeInBits/8) + 1;
    unsigned char tmp[length];

    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);
    
    // Calculate the new total length
    size_t newLength = (src ? strlen(src) : 0) + strlen(tmp) + 1; // +1 for the null terminator
    
    // Reallocate src and check for allocation failure
    unsigned char *newSrc = realloc(src, newLength);
    if (newSrc == NULL) {
        fprintf(stderr, "Error: Unable to reallocate memory\n");
        // Handle error and exit or return as needed
        return 1;
    }
    src = newSrc;

    // Append tmp to src
    strncat(src, tmp, strlen(tmp));
    
    printf("Merged string: %s\n", src);
    
    // Don't forget to free the allocated memory when done
    free(src);

    return 0;
}
