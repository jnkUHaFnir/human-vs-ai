#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_ARRAY_LENGTH 1000
#define MAX_TOKENS 100

void splitTokens(char* charArray, int charArrayLength, char** tokens, int* numTokens) {
    int tokenIndex = 0;
    int tokenStart = 0;
    
    for (int i = 8; i < charArrayLength; i++) {
        if (charArray[i] == '\0') {
            int tokenLength = i - tokenStart;
            if (tokenLength > 0) {
                tokens[tokenIndex] = (char*)malloc(tokenLength + 1); // +1 for null terminator
                memcpy(tokens[tokenIndex], &charArray[tokenStart], tokenLength);
                tokens[tokenIndex][tokenLength] = '\0'; // Null-terminate the token
                tokenIndex++;
                tokenStart = i + 1;
                
                if (tokenIndex >= MAX_TOKENS) {
                    fprintf(stderr, "Exceeded maximum number of tokens\n");
                    break;
                }
            }
        }
    }
    
    *numTokens = tokenIndex;
}

int main() {
    char charArray[CHAR_ARRAY_LENGTH]; // Assuming this is filled with data
    // Fill charArray with data from the network recv function

    // Assuming the array length in your case
    int charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

    char* tokens[MAX_TOKENS]; 
    int numTokens = 0;

    splitTokens(charArray, charArrayLength, tokens, &numTokens);

    for (int i = 0; i < numTokens; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]); // Free dynamically allocated memory
    }

    return 0;
}
