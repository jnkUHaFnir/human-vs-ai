#include <stdio.h>
#include <string.h>

void toUpper(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main() {
    char string[20];

    printf("Enter any string:\n");
    scanf("%s", string);

    toUpper(string);

    printf("The string in upper case is: %s\n", string);

    return 0;
}
