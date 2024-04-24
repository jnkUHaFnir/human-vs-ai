#include <string.h>

int are_overlapping(const char *a, const char *b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    
    if(a > b) {
        return (b + len_b > a);
    } else {
        return (a + len_a > b);
    }
}
