#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num) {
    int i;
    if(num < 2) {
        return 0;
    }

    for(i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find n prime numbers
void find_primes(int n) {
    int *primes = (int *)malloc(n * sizeof(int));
    int count = 0;
    int current = 2; // Start checking from 2

    while(count < n) {
        if(is_prime(current)) {
            primes[count] = current;
            count++;
        }
        current++;
    }

    printf("First %d prime numbers are: ", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
}

int main() {
    int n;

    do {
        printf("Enter the number of prime numbers to find: ");
        scanf("%d", &n);
    } while (n <= 0);

    find_primes(n);

    return 0;
}
