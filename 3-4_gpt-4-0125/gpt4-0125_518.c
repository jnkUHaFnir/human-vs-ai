#include <stdio.h>
#define BUFFER_SIZE 1000000  // Define buffer size

int main() {
    char source[BUFFER_SIZE] = {0};  // Initialize the buffer to zero
    FILE *fp = fopen("TheFile.txt", "r");
    int symbol;
    size_t currentPos = 0;

    if (fp != NULL) {
        while ((symbol = fgetc(fp)) != EOF) {
            if (currentPos < BUFFER_SIZE - 1) {  // Ensure there's room for null terminator
                source[currentPos++] = (char)symbol;  // Add the char and increment the position
            } else {
                // Buffer is full, handle the error or break
                break;
            }
        }
        source[currentPos] = '\0';  // Null-terminate the string
        fclose(fp);
    } else {
        // Handle error opening file
    }

    // Process characters in the buffer
    char c;
    for (int x = 0; (c = source[x]) != '\0'; x++) {
        //Process chars
    }

    return 0;
}
