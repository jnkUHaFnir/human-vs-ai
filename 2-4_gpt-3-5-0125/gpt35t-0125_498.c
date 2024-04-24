#include <stdio.h>
#include <string.h>

void deldigit(char* str) {
    char* dest = str;
    while(*str) {
        if(*str < '0' || *str > '9') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';
    printf("%s", dest);
}

int main() {
    char str[100];

    printf("Enter a word: ");
    scanf("%s", str);
    deldigit(str);

    return 0;
}
