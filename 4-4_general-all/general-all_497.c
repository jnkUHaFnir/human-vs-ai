#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char *result = str; // Create a separate pointer to the start of the string
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            str++; // Skip the digit
        } else {
            *result = *str; // Copy non-digit character to result
            result++;
            str++;
        }
    }
    *result = '\0'; // Add the null terminator at the end
    printf("%s\n", str);
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
