#include <stdio.h>

unsigned char divide_by_10(unsigned char *arr, int size) {
    int i;
    unsigned int remainder = 0;
    for (i = 0; i < size; ++i) {
        remainder = remainder * 256 + arr[i];
        arr[i] = remainder / 10;
        remainder %= 10;
    }
    
    return remainder;
}

void print_base10_number(unsigned char *arr, int size) {
    unsigned char result[256] = { 0 };
    int result_size = 0;

    while (size > 0) {
        result[result_size++] = divide_by_10(arr, size);
        
        while (size > 0 && arr[size - 1] == 0) {
            --size;
        }
    }

    while (result_size > 0) {
        printf("%d", result[--result_size]);
    }
}

int main() {
    unsigned char n[3];

    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    print_base10_number(n, 3);
    return 0;
}
