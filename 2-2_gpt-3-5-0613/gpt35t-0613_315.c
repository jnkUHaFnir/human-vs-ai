#include <stdio.h>

void printBase10(unsigned char *n, size_t size) {
    // Calculate the base 10 number
    unsigned long long num = 0;
    for (size_t i = 0; i < size; i++) {
        num = num * 256 + n[i];
    }
    
    // Print the base 10 number
    printf("%llu\n", num);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    printBase10(n, 3);
    
    return 0;
}
