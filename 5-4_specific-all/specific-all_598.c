#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *convert_to_16(const char *characters, size_t n){
    char sub_buffer[3];
    char *buffer = (char*)malloc(n * 2 + 1); // Allocate memory for the output string + null terminator
    if (buffer == NULL) {
        return NULL; // Handle allocation failure
    }
    buffer[0] = '\0'; // Initialize buffer with null terminator

    for(size_t i = 0; i < n; i++){
        snprintf(sub_buffer, sizeof(sub_buffer), "%02x", (unsigned char)characters[i]); // Use snprintf for secure formatting
        strncat(buffer, sub_buffer, 2);
    } 
    return buffer;
}

// main() only for test
int main(){
    const char param[] = "ABCDEFGHTUIKLL";
    printf("%s\n", param);
    size_t length = strlen(param);
    char *converted = convert_to_16(param, length);
    if (converted != NULL) {
        printf("%s\n", converted);
        free(converted); // Free the memory allocated for the converted string
    } else {
        printf("Memory allocation failed\n");
    }
}
