#include <stdio.h>
#include <string.h>

char* removeDup(char *string);

int main() {
    char string[80];
    scanf("%79s", string); // Read input string and limit input length to avoid buffer overflow
    puts(removeDup(string));
    return 0;
}

char* removeDup(char *string) {
    static char newString[80]; // Use static to keep the array valid outside the function
    int i, c = 0;

    for (i = 0; i < strlen(string); i++) {
        if (string[i] != string[i + 1] && string[i] != '\0') { // Also check for string end
            newString[c++] = string[i];
        }
    }
    newString[c] = '\0'; // Null-terminate the new string
    return newString;
}
