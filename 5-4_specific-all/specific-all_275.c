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
    int bufferlen;
    int sum = 0;
    int value = 0;
    int inNumber = 0;  // Flag to indicate if currently parsing a number
    char result[10];

    bufferlen = strlen(buffer);
    for (int i = 0; i < bufferlen; i++) {
        if (isNumeric(buffer[i])) {
            value = value * 10 + (buffer[i] - '0');
            inNumber = 1;
        } else {
            if (inNumber) {
                sum += value;
                value = 0;
                inNumber = 0;

                // Shift characters to the left to replace the parsed number
                memmove(&buffer[i - 1 - (int)floor(log10(sum))], &buffer[i], bufferlen - i + 1);

                // Convert the sum to string and insert back into the buffer
                int2string(sum, result);
                memcpy(&buffer[i - 1 - (int)floor(log10(sum))], result, strlen(result));

                bufferlen = strlen(buffer);  // Update buffer length after modification
            }
        }
    }

    printf("Result: %s\n", buffer);
}

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();

    return 0;
}
