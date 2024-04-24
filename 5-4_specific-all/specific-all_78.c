#include <stdio.h>

// Function to generate the next permutation given the current permutation
int nextPerm(int perm[], int k, int n) {
    // Marks if the current permutation is invalid
    int invalid = 1;
    int subject, i;

    // If k is 1, handle the simple case directly
    if (k == 1) {
        if (perm[0] == n - 1)
            return 0;
        else {
            perm[0]++;
            return 1;
        }
    }

    // Determine the subject element for the next permutation
    subject = perm[k - 1] + 1;
    
    while (invalid) {
        if (subject == n) {
            subject = 0;
            if (!nextPerm(perm, k - 1, n))
                return 0;
        }
        // Check for invalid permutation
        for (i = 0; i < k - 1; i++) {
            if (perm[i] != subject)
                invalid = 0; // Valid permutation
            else {
                invalid = 1; // Invalid, increment subject
                subject++;
                break;
            }
        }
    }
    perm[k - 1] = subject;
    return 1;
}

int main() {
    int k = 2; // Length of permutations
    int n = 4; // Range for permutations
    int perm[2] = { 0, 1 }; // Starting permutation
    unsigned long long count = 0;

    // Generate permutations using lazy iterator
    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);

        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
