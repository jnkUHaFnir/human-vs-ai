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
    char* newString;
    char* spaceString;
    char* toConcat;
    char* finalString;
    int finalStringLength = 1;  // Start with the null terminator

    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", (int)strlen(str));

    finalString = malloc(finalStringLength);  // Allocates memory for finalString
    if (finalString == NULL) {
        perror("Could not allocate memory for finalString");
        return NULL;
    }
    finalString[0] = '\0'; // Sets first character to null terminator

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str + 1; // Include the '/' character

        newString = substr(str, oldPosition, charPosition - oldPosition);
        toConcat = newString;
        oldPosition = charPosition;

        if (charPosition > 1 && str[charPosition - 2] != ' ') {
            spaceString = malloc(strlen(newString) + 2);
            if (spaceString == NULL) {
                perror("Could not allocate memory for spaceString");
                free(newString);
                free(finalString);
                return NULL;
            }
            sprintf(spaceString, " %s", newString); // Using sprintf to prepend the space
            free(newString); // Freeing the old newString because we're using spaceString now
            toConcat = spaceString;
        }

        // Update the length of finalString for the new content
        finalStringLength += strlen(toConcat);
        finalString = realloc(finalString, finalStringLength);
        if (finalString == NULL) {
            perror("Could not reallocate memory for finalString");
            free(toConcat);
            return NULL;
        }

        strcat(finalString, toConcat); // Concatenate the resulting string to finalString
        free(toConcat);

        position = strchr(position + 1, '/');
    }

    // Capture the remaining part of the string, which does not end with '/'
    toConcat = substr(str, oldPosition, strlen(str) - oldPosition);
    finalStringLength += strlen(toConcat);
    finalString = realloc(finalString, finalStringLength);
    if (finalString == NULL) {
        perror("Could not reallocate memory for finalString");
        free(toConcat);
        return NULL;
    }

    strcat(finalString, toConcat); // Concatenate the remaining string to finalString
    free(toConcat);

    return finalString;
}

int main() {
    char testString[] = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* correctedString = fixString(testString);
    printf("%s\n", correctedString);
    free(correctedString); // Free the string after use

    return 0;
}
