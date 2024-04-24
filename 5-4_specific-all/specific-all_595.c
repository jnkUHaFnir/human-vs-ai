#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 44721

int main() {
    long long int test, i, j, n, m, x, a[1000006];
    long long int *store = (long long int*)malloc(1000009 * sizeof(long long int));
    if(store == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
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
    printf("%lld", a[1]);
    
    free(store); // Free dynamically allocated memory
    return 0;
}
