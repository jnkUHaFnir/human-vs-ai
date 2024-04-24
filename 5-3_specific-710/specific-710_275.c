#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumeric(char c) {
    return isdigit((unsigned char)c);
}

int string2int(char *str) {
    return atoi(str);
}

void int2string(int num, char* str) {
    sprintf(str, "%d", num);
}

void adder(void) {
    char buffer[50] = "2+3+5+2";
    int i = 0;

    while (buffer[i]) {
        if (isNumeric(buffer[i])) {
            int value = string2int(&buffer[i]);

            while (isNumeric(buffer[i + 1])) {
                i++; // Move to the end of the number
            }

            // Calculate sum
            value += string2int(&buffer[i + 1]);

            // Replace the two operands with the result in the buffer
            char result[10];
            int2string(value, result);
            int resultLen = strlen(result);

            memmove(&buffer[i - resultLen + 1], result, resultLen + 1);
            i = i - resultLen + 1;
        }

        i++;
    }

    printf("Result: %s\n", buffer);
}

int main() {
    adder();
    return 0;
}
