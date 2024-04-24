#include <stdio.h>

// Function to generate the next permutation
int next_permutation(int perm[], int k, int n) {
    int subject = k - 1;
    
    // Find the rightmost element smaller than its next element
    while (subject > 0 && perm[subject - 1] >= perm[subject]) {
        subject--;
    }
    
    if (subject == 0) {
        // If no such element exists, this is the last permutation
        return 0;
    }
    
    int j = k - 1;
    
    // Find the rightmost element greater than the pivot
    while (perm[j] <= perm[subject - 1]) {
        j--;
    }
    
    // Swap the pivot with the greater element
    int temp = perm[subject - 1];
    perm[subject - 1] = perm[j];
    perm[j] = temp;
    
    // Reverse the suffix
    j = k - 1;
    while (subject < j) {
        temp = perm[subject];
        perm[subject] = perm[j];
        perm[j] = temp;
        subject++;
        j--;
    }
    
    return 1;
}

int main() {
    int k = 3, n = 10;  // Number of elements to permute and range
    int perm[3] = {0, 1, 2}; // Starting permutation
    
    unsigned long long count = 0;
    
    do {
        // Output the current permutation
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        
        count++;
    } while (next_permutation(perm, k, n));
    
    printf("\nNumber of permutations: %llu\n", count);
    
    getchar();
    return 0;
}
