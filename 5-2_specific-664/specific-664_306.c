#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    char *b = (*a).digits;
    int non_zero_found = 0;

    // Find the first non-zero digit
    while (*b) {
        if (*b != '0') {
            non_zero_found = 1;
            break;
        }
        b++;
    }

    // If a non-zero digit was found, move the rest of the string to the beginning
    if (non_zero_found) {
        memmove((*a).digits, b, strlen(b) + 1); // +1 to copy the null terminator
    } else {
        // If all digits are zero, keep one zero
        (*a).digits[0] = '0';
        (*a).digits[1] = '\0';
    }
}
