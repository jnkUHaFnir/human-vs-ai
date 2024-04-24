#include <stdio.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    // Calculate the base 10 value
    int base10Value = 0;
    int power = 1;
    for (int i = 0; i < 3; i++) {
        base10Value += n[i] * power;
        power *= 256;
    }

    // Print the base 10 value
    printf("%d\n", base10Value);

    return 0;
}
