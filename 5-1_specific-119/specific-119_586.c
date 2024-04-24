#include <stdio.h>
#include <stdbool.h>

int nextPerm(int perm[], int k, int n) {
    bool invalid = true;
    int subject, i;
    
    if (k == 1) {
        if (perm[0] == n - 1) {
            return 0;
        } else {
            perm[0]++;
            return 1;
        }
    }

    subject = perm[k - 1] + 1;
    
    while (invalid) {
        if (subject == n) {
            subject = 0;
            if (!nextPerm(perm, k - 1, n)) {
                return 0;
            }
        }

        invalid = false;
        for (i = 0; i < k - 1; i++) {
            if (perm[i] == subject) {
                invalid = true;
                subject++;
                break;
            }
        }
    }

    perm[k - 1] = subject;
    return 1;
}

int main() {
    int k = 3, n = 10;
    int perm[3] = {0, 1, 2}; // Starting permutation
    unsigned long long count = 0;

    do {
        for (int a = 0; a < k - 1; a++) {
            printf("%d, ", perm[a]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
