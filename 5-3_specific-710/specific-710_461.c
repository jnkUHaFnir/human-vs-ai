#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDup(char *string);

int main() {
    char string[80];
    scanf("%79s", string);  // Limit input to 79 characters to avoid buffer overflow
    puts(removeDup(string));
    return 0;
}

char* removeDup(char *string) {
    int i, c = 0;
    char* newString = (char*) malloc(strlen(string) + 1);  // Allocate memory for the new string

    if (newString == NULL) {
        return NULL;
    }

    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1] && string[i] != '\0') {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0';  // Add null terminator to the end of the new string
    return newString;
}
