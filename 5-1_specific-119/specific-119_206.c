#include <string.h>

int are_overlapping(const char *a, const char *b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    if (a <= b && b < a + len_a) {
        return 1; // overlapping
    } else if (b <= a && a < b + len_b) {
        return 1; // overlapping
    } else {
        return 0; // not overlapping
    }
}
