#include <stdio.h>
#include <string.h>

int main() {
    char re[size_data];
    strncpy(re, data, size_data);  // data is the buffer and size_data the buffer size
    char *token = strtok(re, " "); // Tokenize by space
    if (token != NULL && strcmp(token, "POST") == 0) {
        // First word is "POST", do something
        printf("First word is POST\n");
    } else {
        printf("First word is not POST\n");
    }

    return 0;
}
