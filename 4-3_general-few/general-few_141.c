#include <stdio.h>
#include <string.h>

int allBytesAreZero(unsigned char* array, size_t size) {
    unsigned char zeroArray[size];
    memset(zeroArray, 0, size); // Initialize with zeros

    return memcmp(array, zeroArray, size) == 0;
}

int main() {
    unsigned char arr1[] = {0, 0, 0, 0, 0, 0};
    unsigned char arr2[] = {0, 1, 2, 0, 0, 0};

    if (allBytesAreZero(arr1, sizeof(arr1))) {
        printf("All bytes in arr1 are zero.\n");
    } else {
        printf("Not all bytes in arr1 are zero.\n");
    }

    if (allBytesAreZero(arr2, sizeof(arr2))) {
        printf("All bytes in arr2 are zero.\n");
    } else {
        printf("Not all bytes in arr2 are zero.\n");
    }

    return 0;
}
