#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDup(char *string) {
    int i, c = 0;
    char* newString = (char*)malloc(strlen(string) + 1); // +1 for the null terminator
    newString[0] = string[0]; // Copy the first character directly

    for (i = 1; i < strlen(string); i++) {
        if (string[i] != string[i - 1]) {
            newString[++c] = string[i];
        }
    }
    newString[++c] = '\0'; // Add null terminator to the end of the new string

    return newString;
}

int main() {
    char string[80];
    scanf("%79s", string); // Limit input to avoid buffer overflow
    char* result = removeDup(string);
    
    printf("%s\n", result);

    // Remember to free the dynamically allocated memory
    free(result);

    return 0;
}
