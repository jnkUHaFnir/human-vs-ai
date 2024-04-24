#include <stdio.h>
#include <stdint.h>

void printLargeNumber(unsigned char* num, size_t size) {
    // Initialize variables
    uint64_t result = 0;
    uint64_t base = 1;

    // Process the array from right to left
    for (int i = size - 1; i >= 0; i--) {
        result += num[i] * base;
        base *= 256; // Update the base by multiplying 256
    }

    // Print the result in base 10
    printf("%" PRIu64 "\n", result);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    printLargeNumber(n, 3);

    return 0;
}
