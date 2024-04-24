#include <stdio.h>
#include <string.h>

void printLargeNumber(unsigned char *num, int size) {
    char decimal[size * 3]; // Each byte needs up to 3 characters in base 10, plus a '\0' terminator
    char temp[size * 3]; // Temporary buffer for calculations
    int i, j, carry;

    decimal[0] = '\0'; // Initialize the string

    for (i = size - 1; i >= 0; i--) {
        carry = 0;

        // Multiply current decimal value by 256
        for (j = 0; j < strlen(decimal); j++) {
            snprintf(temp, sizeof(temp), "%d", (decimal[j] - '0') * 256 + carry);
            carry = (temp[j] - '0') / 10;
            decimal[j] = (temp[j] - '0') % 10 + '0';
        }

        while (carry) {
            decimal[j++] = carry % 10 + '0';
            carry /= 10;
        }
    }

    // Print the resulting decimal value
    for (i = strlen(decimal) - 1; i >= 0; i--) {
        printf("%c", decimal[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    
    printLargeNumber(n, 3);

    return 0;
}
