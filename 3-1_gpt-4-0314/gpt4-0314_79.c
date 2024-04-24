#include <stdio.h>
#include <stdbool.h>

void backtrackPermutations(int current[], int k, int n, int depth) {
    if (depth == k) {
        // We've reached a valid permutation
        for (int i = 0; i < k; i++)
            printf("%d ", current[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        bool already_used = false;

        // Check if the number already exists in the current permutation
        for (int j = 0; j < depth; j++)
            if (current[j] == i)
                already_used = true;

        if (!already_used) {
            current[depth] = i;
            backtrackPermutations(current, k, n, depth + 1);
        }
    }
}

int main() {
    int k = 2, n = 4;
    int current[k];
    backtrackPermutations(current, k, n, 0);

    return 0;
}
