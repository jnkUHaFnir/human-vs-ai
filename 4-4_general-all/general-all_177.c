#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** DoThis(int n, int arr[n], int targetArr[n], int level) {
    int l = n;
    int **b = malloc(l * sizeof(*b));
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;

        // Check if current output matches the target array
        if (memcmp(copy, targetArr, n * sizeof(int)) == 0) {
            // If match found, free the memory and return the current level
            for (k = 0; k < l; k++)
                free(b[k]);
            free(b);
            free(copy);
            return level;
        } else {
            // If no match, recursively call DoThis with the new output
            b[i] = copy;
            int **result = DoThis(n, copy, targetArr, level + 1);
            if (result != NULL) {
                // If match found in the recursive call, return the level
                free(copy);
                free(b);
                return result;
            }
        }
    }

    // No match found in this level or any further level, free memory and return NULL
    for (i = 0; i < l; i++)
        free(b[i]);
    free(b);
    return NULL;
}

int main() {
    int arr1[] = {2, 3, 4, 1};
    int arr2[] = {1, 2, 4, 3};
    int target[] = {1, 2, 4, 3};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int level = 1; // Start from level 1

    int **result = DoThis(n, arr1, target, level);

    if (result != NULL) {
        printf("Target array found at level: %d\n", *result);
    } else {
        printf("Target array not found in the generated outputs.\n");
    }

    return 0;
}
