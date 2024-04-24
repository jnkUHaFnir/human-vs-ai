#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n], int target[], int targetSize, int *level) {
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

        // Check if current array matches the target array
        int match = 1;
        for (k = 0; k < targetSize; k++) {
            if (copy[k] != target[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            *level = 2;
            return b;
        }
    }

    return b;
}

int main() {
    int a[] = {2, 3, 4, 1};

    int b[] = {1, 2, 4, 3};
    int targetSize = sizeof(b) / sizeof(b[0]);

    int level = 1;
    int **result = DoThis(sizeof(a) / sizeof(a[0]), a, b, targetSize, &level);

    if (level == 2) {
        printf("The target array is found at level %d\n", level);
    } else {
        printf("The target array is not found\n");
    }

    // You can continue processing the result array as needed

    // Free allocated memory
    for (int i = 0; i < 4; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
