#include <stdio.h>
#include <stdbool.h>

bool nextPerm(int perm[], int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[i] + j - i;
    }

    return true;
}

int main() {
    int k = 2, n = 4;
    int perm[] = {0, 1}; // starting permutation

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
    } while (nextPerm(perm, k, n));

    return 0;
}
