#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char* ptr = str;    /* Save start of the string */
    int count = 0;

    while(*str != '\0') {
        /* Changing the condition to include '0' as well */
        if(*str >= '0' && *str <= '9')
            count++;
        else
            *(str - count) = *str;
        str++;
    }

    *(str - count) = '\0';
    printf("%s", ptr);  /* Print the saved string pointer that points to start */
}

int main() {
    char str[100];

    printf("Enter a word: ");
    scanf("%s", str);   /* No need for `&` when scaning a string */
    deldigit(str);

    return 0;
}
