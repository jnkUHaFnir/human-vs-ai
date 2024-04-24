#include <stdio.h>
#include <string.h>

void multiplyBy256(unsigned char *number, int size) {
    int carry = 0;
    
    for (int i = size - 1; i >= 0; i--) {
        int product = number[i] * 256 + carry;
        number[i] = product % 10;
        carry = product / 10;
    }
}

void printNumber(unsigned char *number, int size) {
    for (int i = 0; i < size; i++) {
        multiplyBy256(number, size);
    }
    
    int start = 0;
    while (start < size && number[start] == 0) {
        start++;
    }
    
    if (start == size) {
        printf("0");
    } else {
        for (int i = start; i < size; i++) {
            printf("%u", number[i]);
        }
    }
    
    printf("\n");
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    printNumber(n, 3);
    
    return 0;
}
