#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    char *b = (*a).digits;
    int nonZeroIndex = -1; // Initialize to an invalid index
    
    // Find the index of the first non-zero digit
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] != '0') {
            nonZeroIndex = i;
            break;
        }
    }
    
    if (nonZeroIndex != -1) {
        // Shift the digits to the beginning of the array
        memmove(b, b + nonZeroIndex, strlen(b) - nonZeroIndex + 1);
    } else {
        // If all digits are zero, leave one '0'
        (*a).digits[1] = '\0';
    }
}

int main() {
    struct number num = {"000013204"};
    printf("Before removing zeros: %s\n", num.digits);

    remove_zero(&num);
    printf("After removing zeros: %s\n", num.digits);

    return 0;
}
