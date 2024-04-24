#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* safeConcat(const char* str1, const char* str2, const char* str3) {
    // Calculate total length needed for the concatenated string
    size_t totalLen = strlen(str1) + strlen(str2) + strlen(str3) + 1; // +1 for null terminator
    
    // Allocate memory for the concatenated string
    char* result = (char*)malloc(totalLen);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Copy the strings into the allocated memory
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    
    return result;
}

int main() {
    const char* var = "123";
    const char* foo = "456";
    const char* bar = "789";

    char* message = safeConcat("TEXT ", var, "");
    printf("Message 1: %s\n", message);
    free(message);

    char* message2 = safeConcat("TEXT ", foo, " TEXT ");
    strcat(message2, bar);
    printf("Message 2: %s\n", message2);
    free(message2);

    return 0;
}
