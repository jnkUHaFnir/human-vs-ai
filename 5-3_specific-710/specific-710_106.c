#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendToString(char **str, const char *addition) {
    size_t originalSize = strlen(*str);
    size_t additionSize = strlen(addition);
    
    *str = (char *)realloc(*str, originalSize + additionSize + 1);
    
    if (*str == NULL) {
        // Handle allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    strcpy(*str + originalSize, addition);
}

int main() {
    char *result = (char *)malloc(1); // Start with an empty string
    result[0] = '\0'; // Null-terminate the string
    
    // .. build string out of variable-length data
    char objectToString[100]; // Assume a maximum length for object toString
    
    for (int i = 0; i < arraySize; i++) {
        // Assume 'objectToString' holds the current object's string representation
        appendToString(&result, objectToString);
    }
    
    // .. some parts are conditional
    if (freezeCount < 0)
        appendToString(&result, "]");
    else
        appendToString(&result, ")");
    
    printf("Final result: %s\n", result);
    
    free(result); // Don't forget to free the memory when done
    return 0;
}
