#include <stdio.h>

int main() {
    unsigned char nums[100];
    int i, k;
    /* Initialize nums with values... */
    for (i = 0; i < 100; i++) {
        nums[i] = i+1;  /* As an example */
    }

    /* Now, for the conversion: */
    int print[256] = {0}; /* An array large enough to hold the result. */
    int print_len = 1;
    for (i = 0; i < 100; i++) {
        int carry = nums[i];
        for (k = 0; k < print_len; k++) {  /* multiply and propagate the carry */
            carry += 256 * print[k];
            print[k] = carry % 10;
            carry /= 10;
        }
        while (carry > 0) {  /* dump remaining carry to print[] */
            print[print_len++] = carry % 10;
            carry /= 10;
        }
    }
    /* Now printing the result: */
    for (k = print_len - 1; k >= 0; k--)
        printf("%d", print[k]);
    printf("\n");
    return 0;
}
