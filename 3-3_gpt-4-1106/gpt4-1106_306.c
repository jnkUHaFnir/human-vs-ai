#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    // Pointer to the beginning of the 'digits' array
    char *ptr = (*a).digits;
    // Find the index of the first non-zero digit
    while (*ptr == '0' && *ptr != '\0') {
        ptr++;
    }
    // Calculate the number of non-zero digits
    int num_digits = strlen(ptr);
    // If there are non-zero digits, shift them to the start of 'digits' array
    if (num_digits > 0) {
        memmove((*a).digits, ptr, num_digits);
    }
    // Null-terminate the new string at the appropriate position
    (*a).digits[num_digits] = '\0';
}

int main() {
    struct number a = {"000013204"};
    printf("Original number: %s\n", a.digits);
    remove_zero(&a);
    printf("Number after removing zeroes: %s\n", a.digits);
    return 0;
}
