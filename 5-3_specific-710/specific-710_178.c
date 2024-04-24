#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compareArrays(int n, int* arr1, int* arr2) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
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

int main() {
    int a[] = {2,3,4,1};
    int b[] = {1,2,4,3};
    int n = sizeof(a) / sizeof(a[0]);

    int **output = DoThis(n, a);
    int level = 1;
    bool found = false;

    while (!found) {
        for (int i = 0; i < n; i++) {
            if (compareArrays(n, output[i], b)) {
                found = true;
                break;
            }
        }

        if (!found) {
            int **newOutput = malloc(n * sizeof(*newOutput));
            for (int i = 0; i < n; i++) {
                newOutput[i] = *DoThis(n, output[i]);
            }
            level++;
            free(output);
            output = newOutput;
        }
    }

    printf("Output found at level: %d\n", level);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);

    return 0;
}
