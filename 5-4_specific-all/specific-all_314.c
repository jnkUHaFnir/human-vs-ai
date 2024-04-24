#include <stdio.h>
#include <stdint.h>

uint64_t convertToBase10(unsigned char *arr, size_t size) {
    uint64_t base10 = 0;
    size_t power = 0;

    for (int i = size - 1; i >= 0; i--) {
        // Accumulate the value in base 10
        base10 += arr[i] * (1ULL << (8 * power));
        power++;
    }

    return base10;
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    // Calculate the base 10 representation
    uint64_t base10Number = convertToBase10(n, sizeof(n));

    // Print the base 10 number
    printf("%llu\n", base10Number);

    return 0;
}
