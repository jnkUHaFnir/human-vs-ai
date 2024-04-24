#include <stdio.h>

unsigned char n[3] = {1, 2, 3};

int main() {
    int i;
    unsigned long long result = 0;
    
    for (i = 0; i < sizeof(n); i++) {
        result = result * 256 + n[i];
    }
    
    printf("%llu\n", result);
    
    return 0;
}
