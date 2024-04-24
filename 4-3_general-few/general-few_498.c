#include <stdio.h>
#include <stdlib.h>

void deleteDigit(char* str) {
    char* result = str;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            str++;
        } else {
            *result = *str;
            result++;
            str++;
        }
    }
    
    *result = '\0';
    printf("%s\n", str);
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deleteDigit(str);

    return 0;
}
