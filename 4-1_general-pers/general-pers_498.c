#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* newStr = str; // Pointer to keep track of the new string without digits
    int count = 0;

    while (*str) {
        if (*str >= '1' && *str <= '9') {
            count++;
        } else {
            *newStr = *str; // Copy the character to the new string only if it's not a digit
            newStr++; // Move the new string pointer to the next position
        }
        str++; // Move the original string pointer to the next position
    }

    *newStr = '\0'; // Add null terminator to the new string to mark its end
    printf("Result: %s\n", str);
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
