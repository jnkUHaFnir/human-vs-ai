#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char receivedData[] = "1234567890\01234567890\034567890\0";
    int dataSize = sizeof(receivedData);

    // Start from byte 8
    int startByte = 8;
    int pos = startByte;
    while (pos < dataSize) {
        // Find the end of the current string
        while (pos < dataSize && receivedData[pos] != '\0') {
            pos++;
        }

        // Copy the string
        if (pos > startByte) {
            int stringLength = pos - startByte;
            char *currentString = malloc(stringLength + 1); // +1 for the null terminator
            if (currentString == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            memcpy(currentString, &receivedData[startByte], stringLength);
            currentString[stringLength] = '\0'; // Null-terminate the string

            // Process or store the string as needed
            printf("String: %s\n", currentString);

            free(currentString); // Free the allocated memory
        }

        // Move to the next string
        pos++; // Skip the current NUL character
        startByte = pos;
    }

    return 0;
}
