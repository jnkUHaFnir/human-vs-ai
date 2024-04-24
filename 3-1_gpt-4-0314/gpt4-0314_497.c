#include <stdio.h>
#include <stdlib.h>

void deldigit(char* str) {
    char *start = str; // store the starting address of the string
    int count = 0;

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') // check for '0' to '9'
            count++;
        else
            *(str - count) = *str; /* want this *str after increment to overwrite *(str-count) */
        str++;
    }

    *(str - count) = '\0';
    printf("%s", start); // print from the starting address of the string
}

int main() {
    char str[100];

    printf("inset word");
    scanf("%s", str); // no need to use & here, as str is already a pointer
    deldigit(str);

    return 0;
}
