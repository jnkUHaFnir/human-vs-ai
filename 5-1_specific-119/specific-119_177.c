#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype
int **DoThis(int n, int arr[n], int level, int target[], int target_level, bool *found);

int main() {
    int a[] = {2, 3, 4, 1};
    int target[] = {1, 2, 4, 3};
    int level = 1;
    bool found = false;

    int **output = DoThis(4, a, level, target, level, &found);

    if (found) {
        printf("Target found at level %d\n", level);
    } else {
        printf("Target not found\n");
    }

    // Free allocated memory
    for (int i = 0; i < 4; i++) {
        free(output[i]);
    }
    free(output);

    return 0;
}

int **DoThis(int n, int arr[n], int level, int target[], int target_level, bool *found) {
    int l = n;
    int **b = malloc(l * sizeof(*b));
    
    if (level > target_level) {
        for (int i = 0; i < l; i++) {
            int *copy = malloc(l * sizeof(*copy));
            
            for (int k = 0; k < l; k++)
                copy[k] = arr[k];
            
            int t = copy[i];
            int j = (i + 1) % l;
            copy[i] = copy[j];
            copy[j] = t;
            
            b[i] = copy;

            // Check if the current array matches the target array
            if (memcmp(copy, target, l * sizeof(int)) == 0) {
                *found = true;
                break;
            }
        }

        if (!(*found)) {
            int **new_output = DoThis(n, b[1], level + 1, target, target_level, found); // Recurse with the next level
            return new_output;
        }

    }

    return b; // Return the current level output
}
