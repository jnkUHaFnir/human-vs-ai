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
    int value1, value2, result;
    char *ptr, resultStr[10];

    while (1) {
        // Find the first operand
        value1 = strtol(buffer, &ptr, 10);

        // Find the operator
        char op = *ptr;

        // Find the second operand
        value2 = strtol(ptr + 1, &ptr, 10);

        // Perform the addition
        result = value1 + value2;

        // Convert the result to a string
        int2string(result, resultStr);

        // Replace the operands and operator with the result in the buffer
        size_t len = ptr - buffer + strlen(ptr + 1);
        memmove(buffer, resultStr, strlen(resultStr));
        memmove(buffer + strlen(resultStr), ptr + strlen(ptr + 1), len);

        // Null-terminate the buffer
        buffer[strlen(resultStr) + len] = '\0';

        // Check if buffer contains only the result
        if (strlen(buffer) == strlen(resultStr)) {
            break;
        }
    }
}

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();
    printf("Final result: %s\n", buffer);

    return 0;
}
