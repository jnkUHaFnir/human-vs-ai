#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* dest = str; // Use a separate pointer for the destination of non-digit chars

    while(*str != '\0') {
        if(*str < '0' || *str > '9') {
            *dest = *str; // Copy non-digit characters
            dest++; // Move destination pointer
        }
        str++; // Always move source pointer
    }

    *dest = '\0'; // Null-terminate the modified string
}

int main() {
    char str[100];

    printf("Insert word:\n");
    scanf("%s", str);
    deldigit(str);

    // Now we print the string right after modifying it, no need to move the pointer.
    printf("Result: %s\n", str);

    return 0;
}
