#include <iostream>

void splitCharArray(char* charArray, int arrayLength) {
    char* currentToken = charArray + 8; // Start from byte 8
    char* endOfArray = charArray + arrayLength;

    while (currentToken < endOfArray) {
        std::cout << currentToken << std::endl;

        // Move to the next token
        currentToken += strlen(currentToken) + 1; // Move to the next token after the NUL char
    }
}

int main() {
    char receivedData[] = "12345678\0string1\0string2\0string3\0";

    int arrayLength = sizeof(receivedData);
    splitCharArray(receivedData, arrayLength);

    return 0;
}
