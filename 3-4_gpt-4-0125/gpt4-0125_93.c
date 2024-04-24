#include <stdio.h>
#include <stdlib.h>

char *readLine(void) {
    // Initial size for the input buffer.
    size_t bufferSize = 100;
    size_t inputLen = 0;
    char *buffer = (char *)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    int c; // To read each character
    while ((c = getchar()) != '\n' && c != EOF) {
        buffer[inputLen++] = c;

        // If we exceeded the buffer, increase its size
        if (inputLen == bufferSize) {
            bufferSize += 100;
            buffer = (char *)realloc(buffer, bufferSize * sizeof(char));
            if (buffer == NULL) {
                perror("Unable to reallocate buffer");
                free(buffer);
                exit(1);
            }
        }
    }

    // Null-terminate the string
    buffer[inputLen] = '\0';
    return buffer;
}

int main() {
    printf("Please enter a line of text:\n");

    char *line = readLine();
    printf("You entered: %s\n", line);

    free(line); // Don't forget to free the memory!
    return 0;
}
