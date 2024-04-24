#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator
    
    if(result == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    
    char* concatenatedStr = concatenateStrings(str1, str2);
    
    printf("Result: %s\n", concatenatedStr);
    
    free(concatenatedStr); // Don't forget to free the memory
    
    return 0;
}
