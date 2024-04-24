#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 44721

long long int *store, *a;

int main() {
    long long int test, i, j, n, m, x;
    store = (long long int*)malloc(1000009 * sizeof(long long int));
    a = (long long int*)malloc(1000006 * sizeof(long long int));

    // Check for successful allocation
    if (store == NULL || a == NULL) {
      printf("Memory allocation failed\n");
      return -1;
    }

    scanf("%lld", &test);
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
    printf("%lld\n", a[1]);

    // Free dynamically allocated memory
    free(store);
    free(a);

    return 0;
}
