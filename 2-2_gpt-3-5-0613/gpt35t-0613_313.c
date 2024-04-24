#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    unsigned long long result = 0;

    for (int i = 0; i < 3; i++) {
        result += n[i] * (unsigned long long)pow(256, i);
    }

    printf("%llu\n", result);

    return 0;
}
