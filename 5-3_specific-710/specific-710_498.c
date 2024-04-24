#include <stdio.h>

void deldigit(char* str) {
    char* result = str; // pointer to track the updated string
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            str++; // move to the next character
        } else {
            *result = *str; // copy non-digit character
            result++;
            str++;
        }
    }
    *result = '\0'; // null-terminate the result string
    printf("%s", result);
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
