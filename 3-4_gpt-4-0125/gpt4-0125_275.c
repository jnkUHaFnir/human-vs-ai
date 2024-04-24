#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char buffer[50];

// Placeholder for isNumeric() as isdigit()
int isNumeric(char c) {
    return isdigit((unsigned char)c);
}

// Placeholder for string2int() as atoi()
int string2int(const char* str) {
    return atoi(str);
}

// Function to convert int to string
void int2string(int num, char* str) {
    sprintf(str, "%d", num);
}

// Updated adder function
void adder(void) {
    int bufferlen, i;
  
    while (1) {
        bufferlen = strlen(buffer);
        i = 0;

        while (i < bufferlen) {
            // Variables for storing numbers and operation indices
            int value1 = -1, value2 = -1;
            int opIndex = -1, numStart = -1, numEnd = -1;
            char result[10] = {0};
          
            // Parse first number
            if (isNumeric(buffer[i])) {
                value1 = string2int(&buffer[i]);
                numStart = i;
                while (isNumeric(buffer[i]) && i < bufferlen) i++;
                numEnd = i;
            }
          
            // Find next number after the operator (only considering '+' here)
            if (buffer[i] == '+' && i < bufferlen - 1) {
                opIndex = i;
                // Move to the start of the next number
                i++;
                if (isNumeric(buffer[i])) {
                    value2 = string2int(&buffer[i]);
                    // Move past the number
                    while (isNumeric(buffer[i]) && i < bufferlen) i++;
                }
            }
          
            // If we have two values, add them
            if (value1 != -1 && value2 != -1) {
                int sum = value1 + value2;
                int2string(sum, result);
                int resultLen = strlen(result);
                
                // Construct new buffer content with the result in place
                int shift = opIndex - numStart + (i - opIndex - 1) - resultLen;
                memmove(buffer + numStart + resultLen, buffer + numEnd, bufferlen - numEnd + 1);
                memcpy(buffer + numStart, result, resultLen);
                bufferlen -= shift;
                
                // Start over to catch any other operations
                continue;
            }
            // Increment only if we didn't find an operable expression
            if (opIndex == -1) i++;
        }
        break; // Exit the loop once we've processed the entire buffer
    }
}

int main() {
    // Example usage
    strcpy(buffer, "2+3+5+2");
    adder();
    printf("Result: %s\n", buffer);

    return 0;
}
