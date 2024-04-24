#include <stdio.h>

// Function to find the largest prime factor
unsigned long long largestPrimeFactor(unsigned long long n) {
    unsigned long long i;
    unsigned long long maxPrime = -1;

    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    for (i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }

    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long lpf = largestPrimeFactor(n);
    
    printf("%llu", lpf);
    
    return 0;
}
