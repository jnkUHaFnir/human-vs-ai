#include <stdio.h>
#include <string.h>
#include <ctype.h>

char buffer[50];

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
    int value1, value2, startOffset, remainderOffset, i;
    char result[10];

    while (1) {
        startOffset = remainderOffset = -1;
        value1 = value2 = -1;

        int bufferLen = strlen(buffer);
        for (i = 0; i < bufferLen; i++) {
            if (value1 == -1) {
                if (isNumeric(buffer[i])) {
                    value1 = string2int(&buffer[i]);
                    startOffset = i;
                }
            } else {
                if (buffer[i] == '+') {
                    if (isNumeric(buffer[i + 1])) {
                        value2 = string2int(&buffer[i + 1]);
                        remainderOffset = i + 1;

                        int additionResult = value1 + value2;
                        int2string(additionResult, result);

                        // Replace the addition expression with the result in the buffer
                        memmove(&buffer[startOffset], result, strlen(result) + 1);
                        // Shift the remaining characters to the left
                        memmove(&buffer[startOffset + strlen(result)], &buffer[remainderOffset + 1], bufferLen - remainderOffset);

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

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();
    printf("Result: %s\n", buffer); // Output should be "12"

    return 0;
}
