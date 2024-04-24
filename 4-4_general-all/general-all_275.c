#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void adder(void) {
    int bufferlen = strlen(buffer);
    int sum = 0;
    int start = 0;
    int i;

    for (i = 0; i <= bufferlen; i++) {
        if (buffer[i] == '+' || i == bufferlen) {
            sum += string2int(&buffer[start]);
            start = i + 1;
        }
    }

    char result[10];
    int2string(sum, result);

    // Replace the part of the buffer where the addition operation was with the result
    memmove(buffer, result, strlen(result) + 1);
}

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();
    printf("Result: %s\n", buffer);

    return 0;
}
