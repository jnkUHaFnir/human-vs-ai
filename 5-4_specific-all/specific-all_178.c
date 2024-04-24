#include <stdio.h>
#include <stdlib.h>

void printArray(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int **DoThis(int n, int arr[n], int level) {
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
        //printf("{%d, %d, %d, %d}\n", copy[0], copy[1], copy[2], copy[3]);
        b[i] = copy;

        if (level == 1 && copy[0] == 1 && copy[1] == 2 && copy[2] == 4 && copy[3] == 3) {
            printArray(n, arr);
            printf("Found at level: %d\n", level);
            return level;
        }
    }

    for (i = 0; i < l; i++) {
        int **res = DoThis(n, b[i], level+1);
        if (res != NULL) {
            printf("Found at level: %d\n", level);
            return res;
        }
    }

    return NULL;
}

int main() {
    int a[] = {2, 3, 4, 1}; // Input array
    int n = sizeof(a) / sizeof(a[0]); // Calculate the size of the input array
    int level = 1; // Start level

    DoThis(n, a, level);

    return 0;
}
