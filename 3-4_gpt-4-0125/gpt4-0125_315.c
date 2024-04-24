#include <stdio.h>
#include <string.h>

// Simple function to multiply a 'number' represented as a string by a single digit.
void multiplyByDigit(char *result, const char *number, int digit) {
    int carry = 0;
    int len = strlen(number);
    for (int i = len - 1; i >= 0; --i) {
        int product = (number[i] - '0') * digit + carry;
        result[i + 1] = (product % 10) + '0';
        carry = product / 10;
    }
    if (carry > 0) {
        result[0] = carry + '0';
    } else {
        memmove(result, result + 1, len);
        result[len] = '\0';
    }
}

// Simple function to add two 'numbers' represented as strings.
void add(char *result, const char *numberToAdd) {
    int lenResult = strlen(result);
    int lenToAdd = strlen(numberToAdd);
    int carry = 0;
    for (int i = 0; i < lenResult || i < lenToAdd || carry; ++i) {
        int sum = carry;
        if (i < lenResult) sum += result[lenResult - 1 - i] - '0';
        if (i < lenToAdd) sum += numberToAdd[lenToAdd - 1 - i] - '0';
        carry = sum / 10;
        result[lenResult - i] = (sum % 10) + '0';
    }
    // Handle remaining carry
    if (carry > 0) {
        memmove(result + 1, result, lenResult + 1);
        result[0] = carry + '0';
    }
}

// From the given byte (val), updates the number represented as strings.
void updateBase10Representation(char *base10, int val) {
    char temp[1024] = {0}; // Temporary storage for multiplication
    multiplyByDigit(temp, base10, 256);
    strcpy(base10, temp); // Copy back the result to base10

    // Now add the current byte value to the base10
    char currentValStr[4]; // Large enough to hold any byte value plus null terminator
    sprintf(currentValStr, "%d", val);
    add(base10, currentValStr);
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    char base10[1024] = "0"; // Large enough buffer to hold the result

    for (int i = sizeof(n) / sizeof(n[0]) - 1; i >= 0; --i) {
        updateBase10Representation(base10, n[i]);
    }

    printf("The number in base 10 is: %s\n", base10);
    return 0;
}
