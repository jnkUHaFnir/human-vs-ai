#include <stdio.h>
#include <string.h>

char* removeDup(char *string) {
    static char newString[80];  // Made static so it remains valid after the function returns
    int i, c = 0;
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0';  // Terminate the new string properly
    return newString;
}

void Ex6() {
    char string[80];
    scanf("%79s", string);  // Use %79s for safety to prevent buffer overflow
    printf("%s\n", removeDup(string));
}

int main() {
    Ex6();
    return 0;
}
