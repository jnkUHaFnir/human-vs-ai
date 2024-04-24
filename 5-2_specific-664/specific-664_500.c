#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int main() {
    char input1[255];
    char input2[255];

    fgets(input1, 255, stdin);
    fgets(input2, 255, stdin);

    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    toUpperCase(input1);
    toUpperCase(input2);

    printf("<%s> <%s>\n", input1, input2);

    return 0;
}
