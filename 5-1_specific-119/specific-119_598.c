#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_to_16(char *characters, int n) {
    char sub_buffer[3];
    char code[3];
    char *buffer = (char*)malloc((n*2 + 1) * sizeof(char)); // Allocate memory for buffer
    buffer[0] = '\0'; // Initialize buffer with null terminator

    for(int i = 0; i < n; i++) {
        strncpy(code, characters + i, 1);
        sprintf(sub_buffer, "%x", *code);
        strncat(buffer, sub_buffer, 2);
    } 
    return buffer;
}

// main() only for test
int main() {
    char param[] = "ABCDEFGHTUIKLL";
    printf("%s\n", param);
    int length = strlen(param);
    char *result = convert_to_16(param, length);
    printf("%s\n", result);
    free(result); // Free allocated memory
}
