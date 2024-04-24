#include <stdio.h>

int allBytesAreZero(const unsigned char *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] != 0) {
            return 0; // Not all bytes are zero
        }
    }
    return 1; // All bytes are zero
}

int main() {
    unsigned char byteArray[] = {0, 0, 0, 0, 0};
    size_t size = sizeof(byteArray) / sizeof(byteArray[0]);

    if (allBytesAreZero(byteArray, size)) {
        printf("All bytes are zero!\n");
    } else {
        printf("Not all bytes are zero!\n");
    }

    return 0;
}
