#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *pstr, int start, int numchars) {
    char* pnew = malloc(numchars + 2); // fixed: +2 for possible space and terminator
    if(!pnew){
        printf("Memory allocation failed!");
        exit(1);
    }
    strncpy(pnew, pstr + start, numchars);
    pnew[numchars] = '\0'; // ensure null termination
    return pnew;
}

char* fixString(char str[]) {
    char* position;
    char* newString;
    char* finalString = malloc(strlen(str) + 2); // allocate memory for final result

    if(!finalString){
        printf("Memory allocation failed!");
        exit(1);
    }

    finalString[0] = '\0'; // initial null char

    int oldPosition = 0;
    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        printf("String position: %d->%d\n", oldPosition, charPosition);
        newString = substr(str, oldPosition, charPosition - oldPosition);
        oldPosition = charPosition;
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1]);
            strcat(newString, " "); // concatenate space
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strcat(finalString, newString); // append to final string
        }
        printf("------------\n");
        free(newString); // remember to free directly after use
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str) - oldPosition);
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(lastString); // free last allocated memory
    return finalString;
}

int main() {
    char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* fixedString = fixString(testString);
    printf("%s", fixedString);
    free(fixedString); // remember to free afterwards
    return 0;
}
