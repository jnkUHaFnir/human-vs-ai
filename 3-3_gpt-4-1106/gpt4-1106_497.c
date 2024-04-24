#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* dest = str; // A pointer to track where to copy characters

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9') {
            // It's a digit, do nothing.
        } else {
            *dest = *str; // Copy non-digit characters to destination pointer
            dest++; // Increment destination pointer
        }
        str++; // Increment source pointer
    }

    *dest = '\0'; // Null-terminate the string at the new end.
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%99s", str); // Added 99 to limit input size and prevent buffer overflows.
    deldigit(str);

    printf("Result: %s\n", str); // Printing from main after processing

    return 0;
}
