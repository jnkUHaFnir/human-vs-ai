#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_to_16(char *characters, int n) {
    char sub_buffer[3];
    char code;
    char *buffer = (char*)malloc(sizeof(char) * n * 2 + 1); // Allocate memory based on input size
    if (buffer == NULL) {
        return NULL;
    }
    buffer[0] = '\0'; // Initialize buffer as an empty string

    for (int i = 0; i < n; i++) {
        code = characters[i]; // Access character directly, no need for strncpy
        sprintf(sub_buffer, "%02x", code); // Use %02x to ensure 2 characters per code
        strncat(buffer, sub_buffer, 2);
    }

    return buffer;
}

// main() only for test
int main() {
    char param[] = "ABCDEFGHTUIKLL";
    printf("%s\n", param);
    int length = strlen(param);
    printf("%s\n", convert_to_16(param, length));
}
