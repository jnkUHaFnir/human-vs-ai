#include <stdio.h>
#include <ctype.h> // for toupper

void convertToUpper(char* str) {
    while(*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int main() {
    char input1[255], input2[255];

    fgets(input1, 254, stdin);
    fgets(input2, 254, stdin);

    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    convertToUpper(input1);
    convertToUpper(input2);

    printf("<%s> <%s>\n", input1, input2);

    return 0;
}
