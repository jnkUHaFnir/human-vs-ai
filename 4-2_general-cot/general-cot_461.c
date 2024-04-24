#include <stdio.h>
#include <string.h>

char* removeDup(char *string) {
    int i, c = 0;
    char newString[80];
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Add null terminator to end the new string
    char *result = strdup(newString); // Allocate memory and copy newString to result
    return result;
}

int main() {
    char string[80];
    scanf("%79s", string); // Limit input to avoid buffer overflow
    char *result = removeDup(string);
    printf("%s\n", result);
    free(result); // Free allocated memory
    return 0;
}
