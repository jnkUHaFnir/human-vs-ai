#include <stdio.h>

// Function to display the base 10 number
void print_base10(unsigned char n[], int n_length) {
    int result[1000] = {0}, result_length = 1;
    result[0] = 1;

    for (int i = 0; i < n_length; i++) {
        int carry = 0;
        for (int j = 0; j < result_length; j++) {
            int temp = result[j] * 256 + carry;
            result[j] = temp % 10;
            carry = temp / 10;
        }

        while (carry) {
            result[result_length] = carry % 10;
            carry /= 10;
            result_length++;
        }

        int sub_carry = n[i];
        for (int j = 0; j < result_length && sub_carry; j++) {
            int temp = result[j] - sub_carry % 10;
            if (temp < 0) {
                result[j] = (temp + 10) % 10;
                sub_carry = (sub_carry - temp) / 10 + 1;
            } else {
                result[j] = temp;
                sub_carry /= 10;
            }
        }
    }

    for (int i = result_length - 1; i >= 0; i--)
        printf("%d", result[i]);
    printf("\n");
}

int main() {
    unsigned char n[3] = {1, 2, 3};
    print_base10(n, 3);

    return 0;
}
