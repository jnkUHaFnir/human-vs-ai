#include <string.h> // For memcpy function

struct number {
    char digits[11];
};

void remove_zero(struct number *a) {
    // Use a pointer to iterate through the digits
    char *b = (*a).digits;
    
    // Iterate till we find the first non-zero character or reach the end of the string
    while (*b == '0') {
        b++;
    }
    
    // If b now points to the start of string, no leading 0 was present, don't do anything
    // Otherwise, we copy the rest of the string (including the terminating zero) back to the start
    if (b != (*a).digits) {
        memmove((*a).digits, b, strlen(b) + 1);
    }
}
