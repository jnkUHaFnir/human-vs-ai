#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDup(char* string);

int main() {
    char string[80];
    scanf("%s", string);
    printf("%s\n", removeDup(string));
    return 0;
}

char* removeDup(char* string) {
    int i, c = 0;
    static char newString[80]; // declare newString as static

    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }

    newString[c] = '\0'; // add null terminator to newString
    return newString;
}
