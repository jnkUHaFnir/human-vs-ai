#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming parameterArray and i are defined somewhere in your code

int main() {
    unsigned char *src = NULL; // Initialize src to NULL
    int length = (parameterArray[i].sizeInBits/8) + 1;
    unsigned char tmp[length];
    
    memcpy(tmp, (char*)&parameterArray[i].valueU8, length);
    
    // Calculate the required length, including space for null terminator
    int newLength = strlen(src ? src : "") + strlen(tmp) + 1; // Include space for null terminator
    
    src = realloc(src, newLength);
    
    if (src == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // If src was NULL initially, make sure to set the first character to '\0'
    if (src[0] == '\0') {
        src[0] = '\0';
    }
    
    strncat(src, tmp, strlen(tmp));
    
    printf("Merged string: %s\n", src);
    
    free(src); // Don't forget to free allocated memory when done
    
    return 0;
}
