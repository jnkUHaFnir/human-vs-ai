#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    char *b = (*a).digits;
    int nonZeroFound = 0;
    
    // Find the first non-zero digit
    while (*b) {
        if (*b != '0') {
            nonZeroFound = 1;
            break;
        }
        b++;
    }

    // Remove leading zeroes by shifting the rest of the string
    if (nonZeroFound) {
        memmove((*a).digits, b, strlen(b) + 1); // +1 to copy the null terminator as well
    } else {
        // If all are zeroes, keep a single zero
        (*a).digits[0] = '0';
        (*a).digits[1] = '\0'; // Null-terminate the string
    }
}

int main() {
    struct number num = {"000013204"};
    printf("Before: %s\n", num.digits);
    
    remove_zero(&num);
    printf("After: %s\n", num.digits);

    return 0;
}
