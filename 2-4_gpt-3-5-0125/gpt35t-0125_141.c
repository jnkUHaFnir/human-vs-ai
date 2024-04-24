#include <stdio.h>
#include <string.h>

int main() {
    unsigned char arr[] = {0, 0, 0, 0, 0, 0, 0}; // Example array of bytes
    
    if(memcmp(arr, arr + 1, sizeof(arr) - 1) == 0) {
        printf("All bytes in the array are zero.\n");
    } else {
        printf("Not all bytes in the array are zero.\n");
    }
    
    return 0;
}
