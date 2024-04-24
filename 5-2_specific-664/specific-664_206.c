#include <string.h>

int are_overlapping(const char *a, const char *b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    
    if (a <= b && a + len_a > b) {
        return 1; // Overlapping
    } else if (b <= a && b + len_b > a) {
        return 1; // Overlapping
    } else {
        return 0; // Not overlapping
    }
}
