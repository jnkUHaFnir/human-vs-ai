#include <string.h>

int are_overlapping(const char *a, const char *b) {
    const char *a_end = a + strlen(a); // One past the last valid character, akin to end() in C++ iterators
    const char *b_end = b + strlen(b); // Same for b

    // Check if a starts inside b or b starts inside a
    if ((a < b_end && a >= b) || (b < a_end && b >= a)) {
        return 1; // They are overlapping
    }

    return 0; // They are not overlapping
}
