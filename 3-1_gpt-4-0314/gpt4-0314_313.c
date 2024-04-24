#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

void base256_to_base10(unsigned char *n, int len, char *out, size_t out_size) {
    memset(out, '0', out_size - 1);
    out[out_size - 1] = '\0';

    for (int i = 0; i < len; ++i) {
        int carry = n[len - 1 - i];
        for (int j = out_size - 2; j >= 0; --j) {
            int digit = (out[j] - '0') * 256 + carry;
            out[j] = (digit % 10) + '0';
            carry = digit / 10;
        }
    }
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    const size_t out_size = 10; // Increase this value based on your output buffer requirements
    char out[out_size];

    base256_to_base10(n, sizeof(n), out, out_size);
    printf("%s\n", out);

    return 0;
}
