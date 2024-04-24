#include <stdio.h>
#include <stdint.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    
    // Convert the array elements to a uint64_t number
    uint64_t num = 0;
    for (int i = 0; i < 3; i++) {
        num += (uint64_t)n[i] << (i * 8);
    }

    // Print the number in base 10
    printf("%" PRIu64 "\n", num);

    return 0;
}
