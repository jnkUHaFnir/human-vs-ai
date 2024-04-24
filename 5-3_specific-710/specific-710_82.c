#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ConstructString(const char* prefix, int value, const char* suffix) {
    // Determine the length needed for the final string
    int prefixLen = strlen(prefix);
    int suffixLen = strlen(suffix);
    int numLen = snprintf(NULL, 0, "%d", value); // Calculate the length of the number
    int totalLen = prefixLen + numLen + suffixLen + 1; // +1 for null terminator

    // Allocate memory for the final string
    char* finalString = (char*)malloc(totalLen);
    if (finalString == NULL) {
        // Handle memory allocation failure
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Construct the final string
    snprintf(finalString, totalLen, "%s%d%s", prefix, value, suffix);

    return finalString;
}

int main() {
    unsigned short frontVIB = GetWord("@FrontVIB@", 0);
    unsigned short rearVIB = GetWord("@RearVIB@", 0);

    // Construct "*FV200#" and "*RV200#"
    char* stringFV = ConstructString("*FV", frontVIB, "#");
    char* stringRV = ConstructString("*RV", rearVIB, "#");

    // Display the constructed strings
    printf("%s\n", stringFV);
    printf("%s\n", stringRV);

    // Free the dynamically allocated memory
    free(stringFV);
    free(stringRV);

    return 0;
}
