#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deldigit(char* str) {
    char* temp = str;
    int count = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        } else {
            *(temp) = *str;
            temp++;
        }
        str++;
    }

    *temp = '\0';
    printf("%s", str);  // Change str to temp here to print the modified string
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%99s", str);  // Use %99s to prevent buffer overflow

    deldigit(str);

    return 0;
}
