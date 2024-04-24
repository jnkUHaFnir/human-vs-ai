#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    int subject = perm[k - 1] + 1;
    int i;

    while (subject < n) {
        int valid = 1;
        for (i = 0; i < k - 1; i++) {
            if (perm[i] == subject) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            perm[k - 1] = subject;
            return 1;
        }
        
        subject++;
    }

    if (!nextPerm(perm, k - 1, n - 1)) {
        return 0;
    }

    perm[k - 1] = perm[k - 2] + 1;
    return 1;
}

int main() {
    int k = 3; // Length of permutation
    int n = 10; // Range of numbers from 0 to n-1
    int perm[3] = {0, 1, 2}; // Starting permutation
    unsigned long long count = 0;

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);

        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal Permutations: %llu\n", count);

    return 0;
}
