#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 64 // Initial size of the buffer

char* concatenateStrings(int freezeCount) {
    size_t bufferSize = INITIAL_SIZE;
    char* result = (char*)malloc(bufferSize * sizeof(char));
    
    strcpy(result, ""); // Initialize result with an empty string
    
    // .. build string out of variable-length data
    // Loop through your objects and concatenate their string representations
    for (int i = 0; i < 10; i++) { // Assuming 10 objects for demonstration
        // Append object's string representation based on condition
        char objectStr[20]; // Just assume a max size for demo
        sprintf(objectStr, "%d", i); // Object's string representation
        strcat(result, objectStr); // Concatenate the object's string
        
        // Some condition based concatenation
        if (freezeCount < 0) {
            strcat(result, "]");
        } else {
            strcat(result, ")");
        }
    }
    
    return result;
}

int main() {
    int freezeCount = -1;
    char* concatenatedString = concatenateStrings(freezeCount);
    
    printf("Concatenated String: %s\n", concatenatedString);
    
    free(concatenatedString); // Free dynamically allocated memory
    
    return 0;
}
