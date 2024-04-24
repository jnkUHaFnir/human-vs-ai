#include <stdio.h>
#include <math.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    int base = 256;
    int decimal = 0;
    
    for (int i = 0; i < 3; i++) {
        decimal += n[i] * pow(base, i);
    }
    
    printf("%d\n", decimal);
    
    return 0;
}
