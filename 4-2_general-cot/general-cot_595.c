#include <stdio.h>

#define MOD 1000000007
#define MAX 44721
#define SIZE 1000006

int main() {
    long long int test, i, j, store[SIZE], n, m, x, a[SIZE];
    scanf("%lld", &test);
    for (i = 0; i < SIZE; i++) {
        store[i] = 1LL;
    }
    a[0] = 1;

    for (j = 1; j < SIZE; j++) {
        for (i = 1; i < MAX; i++) {
            if (i % 2 == 0) {
                store[i] = (store[i - 1] + store[i]) % MOD;
            }
        }
        a[j] = store[MAX - 1];
    }
    printf("%lld", a[1]);
    return 0;
}
