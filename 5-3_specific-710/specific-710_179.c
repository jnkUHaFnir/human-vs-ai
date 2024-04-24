#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n]);

int FindArray(int n, int arr[n], int level) {
    int i, j;
    int found = 0;
    int **output = DoThis(n, arr);

    for (i = 0; i < n; i++) {
        int match = 1;
        for (j = 0; j < n; j++) {
            if (output[i][j] != arr[j]) {
                match = 0;  // Array doesn't match
                break;
            }
        }
        if (match) {
            found = 1;
            break;
        }
    }

    if (found) {
        free(output); // Free dynamically allocated memory
        return level;
    } else {
        int result = FindArray(n, arr, level + 1);
        free(output); // Free dynamically allocated memory
        return result;
    }
}

int main() {
    int a[] = {2, 3, 4, 1};
    int level = FindArray(4, a, 1);

    printf("Found at level: %d\n", level);

    return 0;
}

int **DoThis(int n, int arr[n]){
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
        b[i] = copy;
    }
    return b;
}
