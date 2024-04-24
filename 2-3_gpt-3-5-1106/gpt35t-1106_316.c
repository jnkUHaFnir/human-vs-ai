#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned long long result = 0;

    for (int i = 0; i < 3; i++) {
        result += n[i];
        if (i < 2) {
            result *= 256;
        }
    }

    printf("%llu\n", result);

    return 0;
}
