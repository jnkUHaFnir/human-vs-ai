#include <stdio.h>
#include <stdbool.h>

bool next_perm(int perm[], int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - (k - i)) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }
    return true;
}

void print_permutations(int k, int n) {
    int perm[k];
    for (int i = 0; i < k; i++) {
        perm[i] = i;
    }
    unsigned long long count = 0;
    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (next_perm(perm, k, n));
    printf("Total permutations: %llu\n", count);
}

int main() {
    int k = 2; // Desired length of permutations
    int n = 4; // Range of elements
    print_permutations(k, n);
    return 0;
}
