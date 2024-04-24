#include <stdio.h>
#include <string.h>

int main() {
    unsigned char data[100]; // your array of bytes
    memset(data, 0, sizeof(data)); // initializing the array with zeros
    
    // Check if all bytes in the array are zero
    if (memcmp(data, (unsigned char[100]){0}, sizeof(data)) == 0) {
        printf("All bytes in the array are zero.\n");
    } else {
        printf("Array contains non-zero byte(s).\n");
    }
    
    return 0;
}
