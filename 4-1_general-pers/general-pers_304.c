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
    char* newString = NULL;
    char* finalString = NULL;
    char* tempString;

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
            
            // Append a space character to newString
            tempString = malloc(strlen(newString) + 2);
            strcpy(tempString, newString);
            strcat(tempString, " ");
            free(newString);
            newString = tempString;
        }

        printf("String: |%s|\n", newString);

        if (finalString == NULL) {
            finalString = strdup(newString);
        } else {
            // Append newString to finalString
            tempString = malloc(strlen(finalString) + strlen(newString) + 1);
            strcpy(tempString, finalString);
            strcat(tempString, newString);
            free(finalString);
            finalString = tempString;
        }
        
        printf("------------\n");
        position = strchr(position + 1, '/');
    }

    char* lastString = substr(str, oldPosition, strlen(str));
    if (finalString == NULL) {
        finalString = strdup(lastString);
    } else {
        // Append lastString to finalString
        tempString = malloc(strlen(finalString) + strlen(lastString) + 1);
        strcpy(tempString, finalString);
        strcat(tempString, lastString);
        free(finalString);
        finalString = tempString;
    }

    printf("lastString: %s\n\n", lastString);
    return finalString;
}

int main() {
    char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* result = fixString(testString);
    printf("%s", result);
    free(result);  // Free the memory allocated in fixString function

    return 0;
}
