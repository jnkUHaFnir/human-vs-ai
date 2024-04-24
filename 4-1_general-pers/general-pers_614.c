#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, count = 0;
    
    do {
        printf("Input the number of prime numbers you want to generate: ");
        scanf("%d", &n);
    } while (n <= 0);

    int *v = (int *)malloc(n * sizeof(int));
    
    for (int num = 2; count < n; num++) {
        if (is_prime(num)) {
            v[count++] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    free(v);
    
    return 0;
}
