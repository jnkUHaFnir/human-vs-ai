#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 256

char* concatStrings(const char* prefix, const char* suffix, int condition) {
    // Allocate initial memory
    size_t totalSize = INITIAL_SIZE;
    char* result = (char*)malloc(totalSize);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // Initialize result with prefix
    strcpy(result, prefix);
    
    // Append suffix based on condition
    if (condition < 0) {
        strcat(result, "]");
    } else {
        strcat(result, ")");
    }

    return result;
}

int main() {
    const char* prefix = "Some Text (";
    const char* suffix = "Data";
    int condition = 1; // Example condition
    
    char* concatenated = concatStrings(prefix, suffix, condition);
    
    printf("Result: %s\n", concatenated);
    
    // Don't forget to free allocated memory
    free(concatenated);
    
    return 0;
}
