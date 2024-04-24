#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of the input string

char* extractBaseName(const char* path) {
    const char* baseName = strrchr(path, '/'); // Find the last occurrence of '/'
    if (baseName != NULL) {
        // Move the pointer to point to the character after '/'
        baseName++;
    } else {
        // If '/' is not found, return the original path
        baseName = path;
    }
    return (char*)baseName;
}

int main() {
    char input[MAX_LENGTH];
    
    printf("Enter the path: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove the newline character if present
    input[strcspn(input, "\n")] = 0;

    char* baseName = extractBaseName(input);
    printf("Base name: %s\n", baseName);

    return 0;
}
