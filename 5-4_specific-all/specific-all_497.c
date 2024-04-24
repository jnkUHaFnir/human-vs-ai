#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* dest = str; // Use a separate pointer for destination
    while(*str) {
        if(*str < '0' || *str > '9') {
            *dest = *str; // Copy character if it's not a digit
            dest++; // Move destination pointer only if character is not a digit
        }
        str++; // Always move source pointer
    }
    *dest = '\0'; // Add null terminator at the end
    printf("%s", dest); // Print the modified string starting from dest
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
