#include <stdio.h>

unsigned long largestPrimeFactor(unsigned long n) {
    unsigned long factor = 2;
    
    while (factor * factor <= n) {
        if (n % factor == 0) {
            n /= factor;
        } else {
            factor++;
        }
    }
    
    return n;
}

int main() {
    unsigned long n, lpf;
    scanf("%lu", &n);
    
    lpf = largestPrimeFactor(n);
    
    printf("%lu\n", lpf);
    return 0;
}
