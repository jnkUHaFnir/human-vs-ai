#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char *result = str; /* Pointer to the result string */

    while(*str) {
        if (*str < '0' || *str > '9') {
            *result = *str; /* Only copy characters that are not digits */
            result++;
        }
        str++;
    }
    *result = '\0'; /* Add null terminator at the end of the new string */
    printf("%s", str); /* Print the sanitized string */
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
