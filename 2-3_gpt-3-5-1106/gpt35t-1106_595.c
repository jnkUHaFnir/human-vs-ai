#include <stdio.h>

#define MOD 1000000007
#define MAX 44721

int main() {
    long long int test, i, j, store[1000009], n, m, x, a[1000006];
    scanf("%lld", &test);
    for (i = 0; i < 1000006; i++) {
        store[i] = 1LL;
    }
    a[0] = 1;

    for (j = 1; j < 1000006; j++) {
        for (i = 1; i < 1000006; i++) {  // Update loop condition to iterate through all elements of store array
            if (i % 2 == 0) {
                store[i] = (store[i - 1] + store[i]) % MOD;
            }
        }
        a[j] = store[1000006 - 1];  // Update array index to access the last element of store array
    }
    printf("%lld", a[1]);
    return 0;
}
