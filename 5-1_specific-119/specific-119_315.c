#include <stdio.h>

#define ARRAY_SIZE 3

int main() {
    unsigned char n[ARRAY_SIZE] = {1, 2, 3};
    unsigned long long int base256_num = 0;

    // Convert from base 256 to a large integer
    for (int i = 0; i < ARRAY_SIZE; i++) {
        base256_num = base256_num * 256 + n[i];
    }

    // Print the number in base 10
    printf("%llu\n", base256_num);

    return 0;
}
