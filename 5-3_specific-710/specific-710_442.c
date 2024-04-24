#include <stdio.h>

void splitTokens(char* charArray, int arrayLength) {
    // Start from byte 8
    int index = 8;

    while (index < arrayLength) {
        int tokenLength = 0;

        // Find the end of the current token
        while (index + tokenLength < arrayLength && charArray[index + tokenLength] != '\0') {
            tokenLength++;
        }

        // Extract and process the token
        char token[tokenLength + 1];  // Add space for null terminator
        memcpy(token, &charArray[index], tokenLength);
        token[tokenLength] = '\0';  // Null-terminate the token

        // Do something with the token (e.g., print it)
        printf("Token: %s\n", token);

        // Move to the next token
        index += tokenLength + 1;  // Move past the current token and the NUL character
    }
}

int main() {
    char receivedArray[] = { /* Your received char array goes here */ };
    int arrayLength = sizeof(receivedArray) / sizeof(receivedArray[0]);

    splitTokens(receivedArray, arrayLength);

    return 0;
}
