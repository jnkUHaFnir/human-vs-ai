#include <stdio.h>
#include <string.h>

int all_bytes_are_zero(const void* ptr, size_t size) {
    char zeros[size];
    memset(zeros, 0, size);
    
    return memcmp(ptr, zeros, size) == 0;
}

int main() {
    unsigned char arr[] = {0, 0, 0, 0, 0}; // Example array

    if (all_bytes_are_zero(arr, sizeof(arr))) {
        printf("All bytes in the array are zero.\n");
    } else {
        printf("Array contains non-zero bytes.\n");
    }

    return 0;
}
