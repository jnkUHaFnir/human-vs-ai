#include <stdio.h>
#include <string.h>

void Ex6() {
    char string[80];
    scanf("%s", string);
    puts(removeDup(string));
}

char* removeDup(char *string) {
    static char newString[80];
    int i, c = 0;
    int len = strlen(string);

    if (len == 0) {
        newString[0] = '\0';
        return newString;
    }

    newString[c++] = string[0];
    for (i = 1; i < len; i++) {
        if (string[i] != string[i - 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Null-terminate the new string
    return newString;
}

int main() {
    Ex6();
    return 0;
}
