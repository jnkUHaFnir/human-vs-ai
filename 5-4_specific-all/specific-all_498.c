#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char *dest = str;  // Destination pointer to write non-digit characters
    while (*str) {
        if (*str < '0' || *str > '9') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';  // Null-terminate the result
    printf("%s\n", str); // Print the result
}

int main() {
    char str[100];

    printf("insert word: ");
    fgets(str, sizeof(str), stdin); // Read a line with spaces
    deldigit(str);

    return 0;
}
