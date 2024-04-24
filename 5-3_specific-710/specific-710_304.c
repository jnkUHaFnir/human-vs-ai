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
    char* finalString = malloc(strlen(str) + 1);
    finalString[0] = '\0'; // Initialize finalString as an empty string

    int oldPosition = 0;

    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        printf("String position: %d->%d\n", oldPosition, charPosition);
        char* newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1]);
            char* space = " ";
            char* temp = malloc(strlen(newString) + strlen(space) + 1);
            strcpy(temp, newString);
            strcat(temp, space);
            free(newString);
            newString = temp;
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strcat(finalString, newString);
        }
        free(newString);

        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(lastString);

    return finalString;
}

int main() {
    char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* result = fixString(testString);
    printf("%s", result);

    free(result); // Don't forget to free the allocated memory

    return 0;
}
