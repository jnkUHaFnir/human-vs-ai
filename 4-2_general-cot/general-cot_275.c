#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char buffer[50];

int isNumeric(char c) {
    return isdigit(c);
}

int string2int(char *s) {
    return atoi(s);
}

void int2string(int num, char *buffer) {
    sprintf(buffer, "%d", num);
}

void adder(void) {
    int bufferlen;
    int value1, value2;
    int startOffset, remainderOffset;
    int i;
    char result[10];

    while (1) {
        startOffset = remainderOffset = -1;
        value1 = value2 = -1;

        bufferlen = strlen(buffer);
        for (i = 0; i < bufferlen; i++) {
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
                        break; // Break out of loop when we find the second operand
                    }
                }
            }
        }

        if (value1 != -1 && value2 != -1) {
            int2string((value1 + value2), result);
            // Update buffer with the result
            int resultlen = strlen(result);
            int shift = resultlen - (remainderOffset - startOffset + 1);
            memmove(&buffer[startOffset], result, resultlen);
            memmove(&buffer[startOffset + resultlen], &buffer[remainderOffset + 1], bufferlen - remainderOffset);
            bufferlen = bufferlen - (remainderOffset - startOffset) + resultlen;

            printf("Updated Buffer: %s\n", buffer);
            
            // Reset values for next iteration
            value1 = value2 = -1;
            i = startOffset + resultlen - 1;
        } else {
            break; // No more additions to perform
        }
    }
}

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();

    return 0;
}
