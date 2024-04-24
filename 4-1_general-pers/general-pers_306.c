#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

// Function to remove leading zeroes from (*a).digits
void remove_zero(struct number *a) {
    char *b = (*a).digits; // Using char pointer instead of char to store the address

    // Find the index of the first non-zero digit
    int firstNonZeroIndex = 0;
    while (b[firstNonZeroIndex] == '0' && b[firstNonZeroIndex] != '\0') {
        firstNonZeroIndex++;
    }

    // Shift digits to remove leading zeroes
    memmove((*a).digits, (*a).digits + firstNonZeroIndex, strlen((*a).digits) - firstNonZeroIndex + 1);
}

int main() {
    struct number num = {"000013204"};

    // Remove leading zeroes
    remove_zero(&num);

    printf("Number after removing leading zeroes: %s\n", num.digits);

    return 0;
}
