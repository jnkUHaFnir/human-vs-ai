#include <stdio.h>
#include <string.h>
#include <ctype.h>

char buffer[50];

int isNumeric(char c) {
    return isdigit(c);
}

int string2int(char *s) {
    return atoi(s);
}

void int2string(int n, char *s) {
    sprintf(s, "%d", n);
}

void adder(void) {
    while (1) {
        int value1, value2;
        char *expression = NULL;
        value1 = value2 = -1;

        expression = strtok(buffer, "+");
        if (expression == NULL) {
            break;
        }
        value1 = atoi(expression);
        
        expression = strtok(NULL, "+");
        if (expression == NULL) {
            break;
        }
        value2 = atoi(expression);

        if (value1 != -1 && value2 != -1) {
            int result = value1 + value2;
            char resultStr[10];
            int2string(result, resultStr);
            int resultLen = strlen(resultStr);
            
            // Copy result back to buffer
            strcpy(buffer, resultStr);
            buffer[resultLen] = '\0';
        }
    }
}

int main() {
    strcpy(buffer, "2+3+5+2");
    adder();
    printf("Result: %s\n", buffer);

    return 0;
}
