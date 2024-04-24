#include <string.h>

int are_overlapping(const char *a, const char *b) {
    // Check for NULL pointers
    if (a == NULL || b == NULL) {
        return 0;
    }

    size_t a_len = strlen(a);
    size_t b_len = strlen(b);

    // Check if the strings are empty
    if (a_len == 0 || b_len == 0) {
        return 0;
    }

    // Calculate the start and end pointers of each string
    const char *a_end = a + a_len - 1;
    const char *b_end = b + b_len - 1;

    // Check for overlap by comparing the ranges
    return (a <= b && b <= a_end) || (b <= a && a <= b_end);
}
