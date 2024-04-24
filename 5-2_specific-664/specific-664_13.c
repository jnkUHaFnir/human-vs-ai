#include <stdio.h>

unsigned long largestPrimeFactor(unsigned long n) {
    unsigned long i;
    unsigned long maxPrime = 0;

    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    for (i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    unsigned long n, lpf;

    printf("Enter a number: ");
    scanf("%lu", &n);

    lpf = largestPrimeFactor(n);

    printf("Largest prime factor: %lu\n", lpf);

    return 0;
}
