#include <stdio.h>

unsigned long long findLargestPrimeFactor(unsigned long long n) {
    unsigned long long i;
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
    unsigned long long n, lpf;
    scanf("%llu", &n);
    
    lpf = findLargestPrimeFactor(n);
    
    printf("%llu", lpf);
    
    return 0;
}
