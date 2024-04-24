#include <stddef.h>

int are_overlapping(const char *a, const char *b) {
    const char *end_a = a;
    const char *end_b = b;

    while (*end_a) {
        end_a++;
    }

    while (*end_b) {
        end_b++;
    }

    return (a <= b && b < end_a) || (b <= a && a < end_b);
}
