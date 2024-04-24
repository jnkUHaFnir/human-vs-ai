#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(const char *pstr, int start, int numchars) {
    char* pnew = malloc(numchars + 1);
    if (pnew == NULL) {
        printf("Memory allocation failed.");
        exit(1); // Exit if memory allocation fails, simple error handling
    }
    strncpy(pnew, pstr + start, numchars);
    pnew[numchars] = '\0';
    return pnew;
}

char* fixString(char str[]) {
    char* position;
    char* finalString = malloc(strlen(str) + 1); // Allocate enough space initially, adjust as per need

    if (finalString == NULL) {
        printf("Memory allocation failed.");
        exit(1); // Exit if memory allocation fails
    }

    finalString[0] = '\0'; // Initialize with an empty string for strcat

    int oldPosition = 0;
    printf("Original str: %s\n", str);
    printf("Original length: %d\n\n", strlen(str));

    position = strchr(str, '/');
    while (position != NULL) {
        int charPosition = position - str;

        printf("String position: %d->%d\n", oldPosition, charPosition);
        char* newString = substr(str, oldPosition, charPosition - oldPosition);

        // Check if a space needs to be inserted
        if (charPosition > 0 && str[charPosition - 1] != ' ') {
            printf("Previous char: %c\n", str[charPosition - 1]);
            char* tempString = malloc(strlen(newString) + 2); // Allocate space for newString + space + '\0'
            if (tempString == NULL) {
                free(newString); // free memory to prevent memory leak
                printf("Memory allocation failed.");
                exit(1);
            }
            strcpy(tempString, newString);
            strcat(tempString, " "); // Add space
            free(newString); // Free the original substring to avoid memory leak
            newString = tempString; // Point newString to the updated content
        }

        printf("String: |%s|\n", newString);
        finalString = realloc(finalString, strlen(finalString) + strlen(newString) + 1); // Ensure finalString has enough space
        strcat(finalString, newString); // Concatenate newString to finalString
        free(newString); // Free the memory allocated by newString to avoid memory leak

        printf("------------\n");
        oldPosition = charPosition;
        position = strchr(position + 1, '/');
    }

    // Add the remaining string after the last '/'
    char* lastString = substr(str, oldPosition, strlen(str) - oldPosition);
    finalString = realloc(finalString, strlen(finalString) + strlen(lastString) + 1); // Ensure finalString has enough space
    strcat(finalString, lastString);
    printf("lastString: %s\n\n", lastString);
    free(lastString);
    
    return finalString;
}

int main() {
    char* testString = "/Filter /FlateDecode/Length 7108/Subtype /Type1C";
    char* fixedString = fixString(testString);
    printf("%s", fixedString);
    free(fixedString); // Don't forget to free the memory allocated by fixString
    
    return 0;
}
