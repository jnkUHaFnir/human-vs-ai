#include <stdio.h>

void deldigit(char* str) {
    char* result = str; // Store the address of the original string

    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        } else {
            *(str - count) = *str;
        }
        str++;
    }

    *(str - count) = '\0';
    printf("%s", result); // Print the modified string
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
