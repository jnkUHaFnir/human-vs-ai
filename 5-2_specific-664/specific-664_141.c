#include <stdio.h>
#include <string.h>

int all_zeros(const void *data, size_t len) {
    const char *ptr = data;
    
    for (size_t i = 0; i < len; i++) {
        if (ptr[i] != 0) {
            return 0; // Not all zeros
        }
    }
    
    return 1; // All zeros
}

int main() {
    unsigned char array[] = {0, 0, 0, 0, 0, 0, 0}; // Example array, all elements are zero
    size_t size = sizeof(array);

    if (all_zeros(array, size)) {
        printf("All bytes are zero\n");
    } else {
        printf("Not all bytes are zero\n");
    }

    return 0;
}
