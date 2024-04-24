#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    int count = 0;
    char* temp = str;

    while(*str != '\0') {
        if(*str >= '0' && *str <= '9')
            count++;
        else
            *(str - count) = *str;
        str++;
    }

    *(str - count) = '\0';
    printf("%s", temp);
}

int main() {
    char str[100];

    printf("insert word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
