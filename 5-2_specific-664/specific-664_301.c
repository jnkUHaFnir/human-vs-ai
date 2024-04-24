#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate strings
char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator
    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    
    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

int main() {
    char* result = concatenateStrings("Initial string: ", "");

    // .. build string out of variable-length data
    // for each object, concatenate its string representation
    // for example:
    char* objectString = "Object1"; // replace this with the actual object's string representation
    result = concatenateStrings(result, objectString);

    // .. some parts are conditional
    int freezeCount = -1; // replace this with your actual condition
    if (freezeCount < 0) {
        char* appendString = "]";
        result = concatenateStrings(result, appendString);
    } else {
        char* appendString = ")";
        result = concatenateStrings(result, appendString);
    }

    // Print the final result
    printf("Final concatenated string: %s\n", result);

    // Don't forget to free the memory allocated
    free(result);

    return 0;
}
