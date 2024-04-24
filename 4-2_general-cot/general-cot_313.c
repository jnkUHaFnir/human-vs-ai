#include <stdio.h>

void multiplyByNumber(unsigned char *num, int len, int multiplier) {
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int product = num[i] * multiplier + carry;
        num[i] = product % 10;
        carry = product / 10;
    }
}

void printLargeNumber(unsigned char *num, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    const int len = 3;
    
    // Multiply each element by 256^i where i is the position from the right
    multiplyByNumber(n, len, 1);
    multiplyByNumber(n, len, 256);
    multiplyByNumber(n, len, 256 * 256);
    
    printLargeNumber(n, len);
    
    return 0;
}
