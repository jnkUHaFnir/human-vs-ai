#include <stdio.h>
#include <stdbool.h>

// Function to generate the next permutation
bool nextPerm(int perm[], int k, int n) {
    bool invalid = true;
    int subject, i;

    if (k == 1) {
        if (perm[0] == n - 1)
            return false;
        else {
            perm[0]++;
            return true;
        }
    }

    subject = perm[k - 1] + 1;

    while (invalid) {
        if (subject == n) {
            subject = 0;
            if (!nextPerm(perm, k - 1, n))
                return false;
        }

        for (i = 0; i < k - 1; i++) {
            if (perm[i] != subject)
                invalid = false;
            else {
                invalid = true;
                subject++;
                break;
            }
        }
    }

    perm[k - 1] = subject;
    return true;
}

int main() {
    int k = 2, n = 4;
    int perm[2] = {0, 1}; // starting permutation
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
