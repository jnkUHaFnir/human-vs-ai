#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeString(char* str) {
    int i, j = 0;
    for(i = 0; str[i]; i++) {
        if(isalnum((unsigned char)str[i]) || isspace((unsigned char)str[i])) {
            str[j++] = str[i];
        } else if (str[i] == '\n') {
            // Skip new lines
        }
    }
    str[j] = '\0';
}

int main() {
    // Assume data contains the string received from the webpage
    char data[] = "Hello\n! This 123 is a test string#$%";

    printf("Original string: %s\n", data);

    sanitizeString(data);

    printf("Sanitized string: %s\n", data);

    return 0;
}
