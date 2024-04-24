#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void convertArrayToBase10(unsigned char arr[], int size, char result[]) {
    unsigned char temp[MAX_SIZE];
    memcpy(temp, arr, size);

    int carry = 0;
    for (int i = size - 1; i >= 0; i--) {
        int digit = temp[i] + carry * 256;
        temp[i] = digit % 10;
        carry = digit / 10;
    }

    int index = 0;
    while (index < size && temp[index] == 0) {
        index++;
    }

    for (int i = index; i < size; i++) {
        result[i - index] = temp[i] + '0';
    }
    result[size - index] = '\0';
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    char result[MAX_SIZE + 1];
    convertArrayToBase10(n, 3, result);

    printf("%s\n", result);

    return 0;
}
