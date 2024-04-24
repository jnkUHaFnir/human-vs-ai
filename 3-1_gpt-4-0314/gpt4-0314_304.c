#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *pstr, int start, int numchars) {
    char* pnew = malloc(numchars + 1);
    strncpy(pnew, pstr + start, numchars);
    pnew[numchars] = '\0';
    return pnew;
}

char* fixString(const char* str) {
    const char* position;
    char* newString;
    char* finalString;

    int oldPosition = 0;
    size_t len = strlen(str) + 1;
    finalString = malloc(len);
    finalString[0] = '\0';

    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", len - 1);

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;
        printf("String position: %d->%d\n", oldPosition, charPosition);
        newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1]);
            newString = realloc(newString, strlen(newString) + 2);
            strcat(newString, " ");
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            finalString = realloc(finalString, strlen(finalString) + strlen(newString) + 1);
            strcat(finalString, newString);
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
        free(newString);
    }
    char* lastString = substr(str, oldPosition, len - oldPosition);
    finalString = realloc(finalString, strlen(finalString) + strlen(lastString) + 1);
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(lastString);

    return finalString;
}

int main() {
    const char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* fixedString = fixString(testString);
    printf("%s", fixedString);

    free(fixedString);
    return 0;
}
