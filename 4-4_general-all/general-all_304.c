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
    char* newString = ""; // This will be a pointer to a read-only memory location
    char* finalString = malloc(strlen(str) + 1); // Allocate memory for the final string
    finalString[0] = '\0'; // Initialize finalString to an empty string

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
            printf("Previous char: %c\n", str[charPosition - 1);
            char* tmp = malloc(strlen(newString) + 2); // Temporary buffer for concatenation
            sprintf(tmp, "%s ", newString);
            free(newString); // Free the original string
            newString = tmp;
        }

        printf("String: |%s|\n", newString);
        if (strlen(newString) > 0) {
            strcat(finalString, newString);
        }
        printf("------------\n");
        position = strchr(position + 1, '/');
    }
    char* lastString = substr(str, oldPosition, strlen(str));
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(lastString); // Free the memory allocated by substr
    return finalString;
}

int main() {
    char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* result = fixString(testString);
    printf("%s\n", result);
    free(result); // Free the memory allocated by fixString

    return 0;
}
