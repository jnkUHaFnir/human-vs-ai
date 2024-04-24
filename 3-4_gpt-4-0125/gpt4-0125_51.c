#include <stdio.h>
#include <stdlib.h>

char* readUnlimitedChars() {
    int bufferSize = 10; // Initial size
    char *buffer = (char*)malloc(sizeof(char) * bufferSize);
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    int count = 0;
    char inputChar;
    while ((inputChar = getchar()) != '\n' && inputChar != EOF) {
        buffer[count++] = inputChar;
        if (count == bufferSize) {
            bufferSize *= 2; // Double the buffer size
            buffer = (char*)realloc(buffer, bufferSize);
            if (buffer == NULL) {
                perror("Unable to reallocate buffer");
                exit(2);
            }
        }
    }
    buffer[count] = '\0'; // Null-terminate the string

    return buffer;
}

int main() {
    printf("Enter the address (end with a newline): ");
    char* address = readUnlimitedChars();
    printf("Address: %s\n", address);
    free(address); // Don't forget to free the allocated memory

    return 0;
}
