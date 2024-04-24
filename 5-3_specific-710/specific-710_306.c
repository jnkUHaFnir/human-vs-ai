#include <stdio.h>
#include <string.h>

struct number {char digits[11];};

void remove_zero(struct number *a) {
    char *b = (*a).digits;

    // Find the first non-zero character
    while (*b && *b == '0') {
        b++;
    }

    // Shift the characters to remove leading zeroes
    memmove((*a).digits, b, strlen(b) + 1);
}

int main() {
    struct number num = {"000013204"};

    printf("Before removing leading zeroes: %s\n", num.digits);
    remove_zero(&num);
    printf("After removing leading zeroes: %s\n", num.digits);

    return 0;
}
