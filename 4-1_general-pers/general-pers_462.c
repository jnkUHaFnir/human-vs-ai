#include <stdio.h>
#include <string.h>

char* removeDup(char *string) {
    int i, c = 0;
    char newString[80];
    
    for (i = 0; i < strlen(string) - 1; i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    
    newString[c++] = string[strlen(string) - 1]; // copy the last character
    newString[c] = '\0'; // don't forget to terminate the string
    
    return newString;
}

int main() {
    char string[80];
    scanf("%s", string);
    printf("%s", removeDup(string));
    return 0;
}
