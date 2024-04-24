#include <stdio.h>

int parseHexToInt(const char *input, int offset) {
    char hexString[5];  // Buffer to store the 4 hex characters
    hexString[0] = input[offset];
    hexString[1] = input[offset + 1];
    hexString[2] = input[offset + 2];
    hexString[3] = input[offset + 3];
    hexString[4] = '\0';  // Null-terminate the string

    int result;
    if (sscanf(hexString, "%x", &result) != 1) {
        // Signal an error if sscanf fails to parse the integer
        return -1; // Or any other error code you prefer
    }

    return result;
}

int main() {
    const char *input = "foo10a4bar";
    int offset = 3;

    int parsedInt = parseHexToInt(input, offset);
    if (parsedInt == -1) {
        printf("Invalid input or parsing error\n");
    } else {
        printf("Parsed integer: %d\n", parsedInt);
    }

    return 0;
}
