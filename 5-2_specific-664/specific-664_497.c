#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* result = str; // Use a separate pointer for writing the result
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            str++; // Skip the digit
        } else {
            *result = *str; // Copy the character to the result
            result++;
            str++;
        }
    }

    *result = '\0'; // Add null terminator to the result string
}

int main() {
    char str[100];

    printf("input word: ");
    scanf("%s", str);

    deldigit(str); // Modify the input string

    printf("result: %s\n", str); // Print the modified string

    return 0;
}
