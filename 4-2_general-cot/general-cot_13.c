#include <stdio.h>

unsigned long largest_prime_factor(unsigned long n) {
    unsigned long i;
    while (n % 2 == 0) {
        n /= 2;
    }
    for (i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
        }
    }
    return n;
}

int main() {
    unsigned long n, lpf;
    scanf("%lu", &n);
    
    lpf = largest_prime_factor(n);
    
    printf("%lu", lpf);
    return 0;
}
