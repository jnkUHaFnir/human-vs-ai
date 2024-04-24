#include <stdio.h>
#include <string.h>

void Ex6() {
    char string[80];
    scanf("%79s", string); // read up to 79 characters to avoid buffer overflow
    puts(removeDup(string));
}

char* removeDup(char *string) {
    int i, c = 0;
    char newString[80];
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // terminate the new string
    return newString;
}

int main() {
    Ex6();
    return 0;
}
