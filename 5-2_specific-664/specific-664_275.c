#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char buffer[50];

int isNumeric(char c) {
    return isdigit(c);
}

int string2int(char *str) {
    return atoi(str);
}

void int2string(int num, char *str) {
    sprintf(str, "%d", num);
}

void adder(void)
{
    int value1, value2;
    int i = 0;
    char result[10];

    while (buffer[i] != '\0') {
        if (isNumeric(buffer[i])) {
            value1 = string2int(&buffer[i]);
            while (isNumeric(buffer[i])) {
                i++;
            }
        } else if (buffer[i] == '+') {
            i++;
            if (isNumeric(buffer[i])) {
                value2 = value1 + string2int(&buffer[i]);
                int2string(value2, result);
                // Replace the expression with the result in the buffer
                memmove(&buffer[i - (int)((size_t)log10(value1) + 1) + 1], result, strlen(result) + 1);
                i = i - (int)((size_t)log10(value1) + 1) + (int)strlen(result);
            }
        } else {
            i++;
        }
    }
}

int main() {
    strcpy(buffer, "2+3+5+2");
    printf("Before: %s\n", buffer);

    adder();

    printf("After: %s\n", buffer);

    return 0;
}
