#include <stdio.h>
#include <string.h>

char* removeDup(char *string);

int main() {
    char string[80];
    scanf("%s", string);
    puts(removeDup(string));
    
    return 0;
}

char* removeDup(char *string) {
    int i, c = 0;
    char newString[80];
    
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    
    newString[c] = '\0'; // Adding null terminator
    
    return newString;
}
