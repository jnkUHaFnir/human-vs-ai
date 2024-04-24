#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *pstr, int start, int numchars) {
    char* pnew = malloc(numchars + 1);
    strncpy(pnew, pstr + start, numchars);
    pnew[numchars] = '\0';
    return pnew;
}

char* fixString(const char *str) {
    char* finalString = malloc(strlen(str) + 1);
    finalString[0] = '\0'; // Initialize the final string

    const char* position = str; // Start from the beginning of the string
    const char* token;

    while ((token = strpbrk(position, "/")) != NULL) {
        size_t tokenLength = token - position;
        char* newString = substr(position, 0, tokenLength);

        if (strlen(finalString) > 0 && finalString[strlen(finalString) - 1] != ' ' && newString[0] != ' ') {
            strcat(finalString, " ");
        }

        strcat(finalString, newString);
        free(newString);

        position = token;
    }

    strcat(finalString, position);

    return finalString;
}

int main() {
    const char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* result = fixString(testString);
    printf("%s", result);

    free(result); // Free the memory allocated for the result

    return 0;
}
