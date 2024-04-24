#include <stdio.h>

unsigned long long convertToDecimal(unsigned char* arr, int size) {
    unsigned long long result = 0;
    unsigned long long power = 1;
    
    for (int i = size - 1; i >= 0; i--) {
        result += arr[i] * power;
        power *= 256;
    }
    
    return result;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    unsigned long long decimal = convertToDecimal(n, sizeof(n)/sizeof(n[0]));
    printf("%llu\n", decimal);
    
    return 0;
}
197121
