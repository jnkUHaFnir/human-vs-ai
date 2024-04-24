#include <stdio.h>

int main() {
    int n = 10, k = 3;
    int bitmask = (1 << k) - 1;
    
    while (bitmask < 1 << n) {
        // Generate permutation from bitmask
        for (int i = 0; i < n; i++) {
            if (bitmask & (1 << i)) {
                printf("%d ", i);
            }
        }
        printf("\n");

        // Increment the bitmask to get the next permutation
        int x = bitmask & -bitmask, y = bitmask + x;
        bitmask = ((bitmask & ~y) / x >> 1) | y;
    }

    return 0;
}
