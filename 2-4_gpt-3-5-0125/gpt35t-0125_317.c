#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    unsigned long long int result = 0;
    int i;

    for(i = 0; i < 3; i++) {
        result = result * 256 + n[i];
    }

    printf("%llu\n", result);

    return 0;
}
