#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num){
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the first N prime numbers
void find_primes(int n){
    int count = 0;
    int num = 2;

    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
}

int main(){
    int n;

    do {
        printf("Input an integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    find_primes(n);

    return 0;
}
