#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *pstr, int start, int numchars) {
    char* pnew = malloc(numchars + 1);
    strncpy(pnew, pstr + start, numchars);
    pnew[numchars] = '\0';
    return pnew;
}

char* fixString(char str[]) {
    char* position;
    char* newString = NULL;  // Initialize as NULL
    char* finalString = malloc(strlen(str) + 1); // Allocate memory for finalString

    int oldPosition = 0;
    printf("Original str: %s\n", str);
    printf("Original length: %zd\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        printf("String position: %d->%d\n", oldPosition, charPosition);
        newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1);
            // Use strncat to avoid buffer overflow
            newString = strncat(newString, " ", 1);
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strncat(finalString, newString, strlen(newString)); // Concatenate newString to finalString
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    strncat(finalString, lastString, strlen(lastString)); // Concatenate lastString to finalString
    printf("lastString: %s\n\n", lastString);
    return finalString;
}

int main() {
    char testString[] = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    printf("%s", fixString(testString));

    return 0;
}
