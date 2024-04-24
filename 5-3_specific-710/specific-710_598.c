#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert_to_16(char *characters, int n) {
    char sub_buffer[3];
    char code[2]; // Change size to 2
    char *buffer = (char*)malloc(sizeof(char) * (n * 2 + 1)); // Allocate memory properly

    buffer[0] = '\0'; // Initialize buffer as an empty string

    for(int i=0; i < n; i++) {
        snprintf(code, 3, "%02x", (unsigned char)characters[i]); // Use snprintf to prevent buffer overflow
        strncat(buffer, code, 2);
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
