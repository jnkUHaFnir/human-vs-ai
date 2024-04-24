#include <stdio.h>
#include <string.h>
#include <ctype.h> // for isalnum

// Function to clean the input string by allowing only letters, numbers, and spaces.
// Note that it will modify the input string directly.
void cleanString(char *str) {
    char *src = str;  // Source pointer
    char *dst = str;  // Destination pointer

    while (*src) {
        if (isalnum((unsigned char)*src) || *src == ' ') {
            *dst++ = *src; // Copy only alphanumeric chars and spaces
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the cleaned string
}

int main() {
    char data[] = "Example\nstring with numbers 1234 and \tspecial characters!@#";
    printf("Original Data: %s\n", data);

    cleanString(data);

    printf("Cleaned Data: %s\n", data);
    return 0;
}
