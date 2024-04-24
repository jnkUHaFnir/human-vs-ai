#include <stdio.h>
#include <stdlib.h>

char* readUnlimitedInput() {
    char* buffer = NULL;
    char tempBuffer[256];  // Temporary buffer to store each line of input

    size_t bufferSize = 0;
    size_t totalSize = 0;

    while (fgets(tempBuffer, sizeof(tempBuffer), stdin) != NULL) {
        size_t lineSize = strlen(tempBuffer);

        char* newBuffer = realloc(buffer, totalSize + lineSize + 1);
        if (newBuffer == NULL) {
            if (buffer) free(buffer);
            return NULL; // Error in memory allocation
        }

        buffer = newBuffer;
        strcpy(buffer + totalSize, tempBuffer);
        totalSize += lineSize;

        if (tempBuffer[lineSize - 1] == '\n') {
            break; // Exit loop if empty line is encountered
        }
    }

    return buffer;
}

int main() {
    char* address = readUnlimitedInput();

    if (address) {
        printf("Address: %s\n", address);
        free(address); // Don't forget to free the memory when done
    } else {
        printf("Error reading address.\n");
    }

    return 0;
}
