#include <stdio.h>
#include <string.h>

char* removeDup(char *string) {
    int i, c = 0;
    static char newString[80]; // Use static array to return from the function

    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1]) {
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Add null terminator to the end of the new string
    return newString;
}

int main() {
    char string[80];
    scanf("%79s", string); // Limit input to prevent buffer overflow
    printf("Original string: %s\n", string);
    printf("After removing consecutive repeated characters: %s\n", removeDup(string));

    return 0;
}
