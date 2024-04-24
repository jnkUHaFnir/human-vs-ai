#include<stdio.h>

int main() {
    unsigned char n[3]; // Your array
    n[0] = 1; n[1] = 2; n[2] = 3;
    int i, j;
    unsigned long long int val; // temporary value
    unsigned long long int base = 1; // base value (will be 256^index)
    for (i = 0; i < 3; i++) {
        val = 0;
        for (j = 0; j <= i; j++) {
            val += n[j] * base;
            base <<= 8; // Shifting by 8 is same as multiplying by 256
        }
        printf("%llu\n", val);
        base = 1;
    }
    return 0;
}
