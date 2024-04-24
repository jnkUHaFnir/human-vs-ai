#include <stdio.h>
#include <math.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    int num_elements = sizeof(n) / sizeof(n[0]);

    long long decimal = 0;
    for (int i = num_elements - 1; i >= 0; i--) {
        decimal += n[i] * pow(256, num_elements - 1 - i);
    }

    printf("%lld\n", decimal);

    return 0;
}
