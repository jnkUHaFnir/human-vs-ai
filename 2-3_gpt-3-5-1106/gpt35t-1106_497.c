#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* original = str;
    char* result = str;

    while (*str) {
        if (*str < '0' || *str > '9') {
            *result = *str;
            result++;
        }
        str++;
    }

    *result = '\0';
    printf("%s", original);
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
