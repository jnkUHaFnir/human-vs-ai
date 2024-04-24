#include <stdio.h>
#include <string.h>

void Ex6() {
    char string[80];
    scanf("%79s", string); // limit input to prevent buffer overflow
    puts(removeDup(string));
}

char* removeDup(char *string) {
    static char newString[80]; // static to retain across function calls
    int i, c = 0;
    newString[c++] = string[0]; // first char is always included
    for (i = 1; i < strlen(string); i++) {
        if (string[i] != ' ' && string[i] != newString[c - 1]) {
            newString[c++] = string[i];
        } else if (string[i] == ' ') {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // add null terminator
    return newString;
}

int main() {
    Ex6();
    return 0;
}
