#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDup(char *string) {
    int i, c = 0;
    char* newString = (char*)malloc(strlen(string) + 1); // +1 for null terminator
    if (newString == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Add null terminator at the end
    return newString;
}

int main() {
    char string[81];
    scanf("%80s", string); // limit input to 80 characters to prevent buffer overflow
    char *result = removeDup(string);
    printf("%s\n", result);

    free(result); // free the dynamically allocated memory
    return 0;
}
