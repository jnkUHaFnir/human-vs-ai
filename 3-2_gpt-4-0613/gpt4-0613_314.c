#include <stdio.h>

#define MAX_DIGITS 1000               // maximum number of digits for base-10 number

void print_base10(unsigned char *n, int size) {
    int result[MAX_DIGITS] = {0};    // array to store the base-10 number
    int result_size = 1;             // number of digits in result

    for (int var_index = size - 1; var_index >= 0; var_index--) {
        int carry = n[var_index];    // multiply result by 256 and add current byte
        for (int res_index = 0; res_index < result_size || carry; res_index++) {
            if (res_index == result_size) {
                result[result_size++] = 0; // expand result if necessary
            }
            int value = result[res_index] * 256 + carry; // calculate product and add carry
            carry = value / 10;                          // calculate new carry
            result[res_index] = value % 10;              // store digit
        }
    }

    // print result
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
}

int main() {
    unsigned char n[3] = {1, 2, 3};

    print_base10(n, 3);

    return 0;
}
