#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(int freezeCount) {
    char *result = (char *)malloc(sizeof(char) * 1); // Allocate initial memory
    result[0] = '\0'; // Ensure string is properly terminated

    // Concatenate strings based on condition
    if (freezeCount < 0) {
        char *str1 = "Hello";
        char *str2 = "World";
        
        // Dynamically allocate memory to hold the combined string
        result = (char *)realloc(result, sizeof(char) * (strlen(result) + strlen(str1) + strlen(str2) + 1));
        
        strcat(result, str1);
        strcat(result, str2);
        strcat(result, "]");
    } else {
        char *str1 = "Goodbye";
        char *str2 = "Everyone";
        
        // Dynamically allocate memory to hold the combined string
        result = (char *)realloc(result, sizeof(char) * (strlen(result) + strlen(str1) + strlen(str2) + 1));
        
        strcat(result, str1);
        strcat(result, str2);
        strcat(result, ")");
    }

    return result;
}

int main() {
    int freezeCount = -1;
    char *finalString = concatenateStrings(freezeCount);
    printf("%s\n", finalString);
    
    free(finalString); // Free dynamically allocated memory
    
    return 0;
}
