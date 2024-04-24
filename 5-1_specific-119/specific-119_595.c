#define MAX 44721
#define SIZE 1000006
int main() {
    long long int test, i, j, store[1000009], n, m, x, a[SIZE]; // Adjust size from 1000006 to 1000006
    scanf("%lld", &test);
    for (i = 0; i < 1000006; i++) {
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
