#include <stdio.h>

void multiplyBy256(unsigned char *num, int size) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int temp = (num[i] * 256) + carry;
        num[i] = temp % 10;
        carry = temp / 10;
    }
}

void printArray(unsigned char* num, int size) {
    int i = size - 1;
    while (num[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        printf("%d", num[i]);
    }
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    const int ARRAY_SIZE = 3;
    const int TARGET_SIZE = 100;

    for (int i = ARRAY_SIZE; i < TARGET_SIZE; i++) {
        multiplyBy256(n, ARRAY_SIZE);
    }

    printArray(n, ARRAY_SIZE);

    return 0;
}
