#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    unsigned long long result = 0;

    int i;
    for (i = 0; i < sizeof(n); i++) {
        result += n[i] * (unsigned long long)1 << (8 * i);
    }

    printf("%llu", result);

    return 0;
}
