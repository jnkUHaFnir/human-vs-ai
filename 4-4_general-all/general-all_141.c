#include <string.h>

int allBytesAreZero(const unsigned char *array, size_t size) {
    // Create a zero-initialized array
    unsigned char zeroArray[size];
    memset(zeroArray, 0, size);

    // Compare the original array with the zero-initialized array
    return memcmp(array, zeroArray, size) == 0;
}

int main() {
    unsigned char data[] = {0, 0, 0, 0}; // Example array
    size_t size = sizeof(data);

    if (allBytesAreZero(data, size)) {
        printf("All bytes are zero\n");
    } else {
        printf("Not all bytes are zero\n");
    }

    return 0;
}
