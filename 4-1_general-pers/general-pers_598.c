#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert_to_16(char *characters, int n) {
    char sub_buffer[3];
    char code[3];
    char *buffer = (char*)malloc((n * 2 + 1) * sizeof(char)); // Allocate memory for the converted string
    buffer[0] = '\0'; // Null-terminate the buffer

    for(int i = 0; i < n; i++) {
        strncpy(code, characters + i, 1);
        sprintf(sub_buffer, "%02x", *code); // Use "%02x" to get 2 characters always
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
