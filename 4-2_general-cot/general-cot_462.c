#include <stdio.h>
#include <string.h>

char* removeDup(char *string);

void Ex6() {
    char string[80];
    scanf("%s", string);
    printf("%s\n", removeDup(string));
}

char* removeDup(char *string) {
    static char newString[80]; // static keyword added for returning correct value
    int i, c = 0;
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Add null terminator at the end
    return newString;
}

int main() {
    Ex6();
    return 0;
}
