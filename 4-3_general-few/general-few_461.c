#include <stdio.h>
#include <string.h>

void removeDup(char *string) {
    int i, c = 0;
    char newString[80];

    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Add null terminator to indicate end of the new string

    printf("%s\n", newString);
}

int main() {
    char string[80];
    scanf("%79s", string); // Limit string input to 79 characters to avoid buffer overflow
    removeDup(string);

    return 0;
}
