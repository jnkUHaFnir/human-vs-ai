#include <stdio.h>
#include <stdlib.h>

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

int findLevel(int n, int arr[n], int searchArr[n], int level) {
    if (n <= 0) {
        return -1; // Input array not found
    }

    for (int i = 0; i < n; i++) {
        if (searchArr[i] != arr[i]) {
            int **output = DoThis(n, arr);
            for (int j = 0; j < n; j++) {
                int result = findLevel(n, output[j], searchArr, level+1);
                if (result != -1) {
                    return result;
                }
            }
            // Clean up allocated memory
            for (int k = 0; k < n; k++) {
                free(output[k]);
            }
            free(output);
            return -1;
        }
    }

    return level;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int searchArr[] = {1, 2, 4, 3};

    int level = findLevel(4, a, searchArr, 1);

    if (level != -1) {
        printf("Found the array at level: %d\n", level);
    } else {
        printf("Array not found.\n");
    }

    return 0;
}
