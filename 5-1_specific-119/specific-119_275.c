#include <stdio.h>
#include <string.h>
#include <ctype.h>

char buffer[50];

void shiftBuffer(char *buffer, int fromIndex, int shiftBy) {
    int i;
    for (i = fromIndex; buffer[i] != '\0'; i++) {
        buffer[i] = buffer[i + shiftBy];
    }
}

void adder(void) {
    int value1, value2;
    int i;
    char result[10];

    while (1) {
        value1 = value2 = -1;

        for (i = 0; i < strlen(buffer); i++) {
            if (value1 == -1) {
                if (isdigit(buffer[i])) {
                    value1 = atoi(&buffer[i]);
                    buffer[i] = ' '; // Replace the first operand in buffer with space
                }
            } else {
                if (buffer[i] == '+') {
                    if (isdigit(buffer[i + 1])) {
                        value2 = atoi(&buffer[i + 1]);
                        int sum = value1 + value2;
                        snprintf(result, 10, "%d", sum);
                        buffer[i] = ' '; // Replace the operator in buffer with space
                        buffer[i + 1] = ' '; // Replace the second operand in buffer with space
                        sprintf(&buffer[i - 2], "%s", result); // Replace the result in buffer
                        shiftBuffer(buffer, i + 1, strlen(result) - 2); // Shift the buffer to the left
                        break;
                    }
                }
            }
        }

        if (value1 == -1 || value2 == -1) {
            break;
        }
    }
}
