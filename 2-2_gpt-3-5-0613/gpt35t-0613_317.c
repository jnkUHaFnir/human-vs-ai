#include <stdio.h>

int main() {
    unsigned char n[3] = {1, 2, 3};
    unsigned int decimal = 0;
    
    for(int i = sizeof(n) - 1; i >= 0; i--) {
        decimal = decimal * 256 + n[i];
    }
    
    printf("%u\n", decimal);
    
    return 0;
}
