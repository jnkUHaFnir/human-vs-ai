#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* base256_to_base10(unsigned char* n, size_t input_len, size_t *output_len) {
    unsigned char* decimal_repr = malloc(input_len * 3 + 1); // Max output length is 3 times input length
    memset(decimal_repr, 0, input_len * 3 + 1);

    int out_idx = 0;
    while (1) {
        int carry = 0;
        int non_zero_found = 0;
        for (int i = input_len - 1; i >= 0; i--) {
            int temp = (n[i] + carry * 256);
            n[i] = temp / 10;
            carry = temp % 10;
            if (n[i] != 0) non_zero_found = 1;
        }
        if (!non_zero_found) break;
        decimal_repr[out_idx++] = carry;
    }

    *output_len = out_idx;
    return decimal_repr;
}

int main() {
    unsigned char n[] = {1, 2, 3};
    size_t input_len = 3;
    size_t output_len;
    unsigned char* decimal_repr = base256_to_base10(n, input_len, &output_len);

    printf("Decimal representation: ");
    for (int i = output_len - 1; i >= 0; i--) {
        printf("%d", decimal_repr[i]);
    }
    printf("\n");

    free(decimal_repr);
    return 0;
}
