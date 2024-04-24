#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 44721

int main() {
    long long int test, i, j, n, m, x, *store, a[1000006];
    scanf("%lld", &test);

    store = (long long int *)malloc(1000006 * sizeof(long long int));
    if (store == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < 1000006; i++) {
        store[i] = 1LL;
    }
    a[0] = 1;

    for (j = 1; j < 1000006; j++) {
        for (i = 1; i < MAX; i++) {
            if (i % 2 == 0) {
                store[i] = (store[i - 1] + store[i]) % MOD;
            }
        }
        a[j] = store[MAX - 1];
    }
    printf("%lld", a[1]);

    free(store); // Don't forget to free the allocated memory
    return 0;
}
