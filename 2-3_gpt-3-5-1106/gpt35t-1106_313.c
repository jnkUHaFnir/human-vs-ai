#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    long long result = 0;
    long long power_of_256 = 1;

    for (int i = 2; i >= 0; i--) {
        result += n[i] * power_of_256;
        power_of_256 *= 256;
    }

    printf("%lld\n", result); // Output: 197121

    return 0;
}
