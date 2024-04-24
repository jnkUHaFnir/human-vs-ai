#include <stdio.h>
#include <string.h>

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    char *b = (*a).digits; // Use char pointer for string manipulation
    int leading_zero = 1;

    // Find the first non-zero character
    while (*b) {
        if (*b != '0') {
            leading_zero = 0;
            break;
        }
        b++;
    }

    if (leading_zero) {
        // If the number is all zeroes, leave a single zero
        (*a).digits[0] = '0';
        (*a).digits[1] = '\0';
    } else {
        // Shift the non-zero part to the beginning of the array
        strcpy((*a).digits, b);
    }
}

int main() {
    struct number num = {"000013204"};
    
    printf("Before: %s\n", num.digits);
    
    remove_zero(&num);
    
    printf("After: %s\n", num.digits);
    
    return 0;
}
