for (j = 1; j < 1000006; j++) {
    for (i = 1; i < MAX; i++) {
        if (i % 2 == 0) {
            store[i] = (store[i - 1] + store[i]) % MOD;
        }
    }
    a[j] = store[MAX - 1];
}
for (j = 1; j < 1000005; j++) {
    for (i = 1; i < MAX; i++) {
        if (i % 2 == 0) {
            store[i] = (store[i - 1] + store[i]) % MOD;
        }
    }
    a[j] = store[MAX - 1];
}
