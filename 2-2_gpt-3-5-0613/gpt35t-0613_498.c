#include <stdio.h>

void deldigit(char* str) {
    int count = 0;

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9')
            count++;
        else
            *(str - count) = *str; /* overwrite *(str-count) with *str */
        str++;
    }

    *(str - count) = '\0';
    printf("Result: %s\n", str - count);
}

int main() {
    char str[100];

    printf("Insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
