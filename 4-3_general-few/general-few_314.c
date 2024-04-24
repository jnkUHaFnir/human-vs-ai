#include <stdio.h>
#include <string.h>
#include <math.h>

void printBase10FromBytes(unsigned char *array, int size) {
    unsigned long long result = 0;
    
    for (int i = 0; i < size; i++) {
        result += (unsigned long long)array[i] * pow(256, i);
    }

    printf("%llu\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printBase10FromBytes(n, 3);

    return 0;
}
