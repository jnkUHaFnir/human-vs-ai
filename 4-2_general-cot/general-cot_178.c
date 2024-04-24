#include <stdio.h>
#include <stdlib.h>

int permute(int level, int n, int arr[n], int *b, int **output){
    int found = 0;
    for (int i = 0; i < n; i++) {
        int *copy = malloc(n * sizeof(*copy));
        for (int k = 0; k < n; k++)
            copy[k] = arr[k];
        int t = copy[level-1];
        copy[level-1] = copy[i];
        copy[i] = t;

        if (level == n) {
            int match = 1;
            for (int j = 0; j < n; j++) {
                if (copy[j] != b[j]) {
                    match = 0;
                    break;
                }
            }
            if (match == 1) {
                found = level;
                break;
            }
        } else {
            int result = permute(level+1, n, copy, b, output);
            if (result > 0) {
                found = result;
                break;
            }
        }
        free(copy);
    }
    return found;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int **output = malloc(n * sizeof(*output));
    
    int level = permute(1, n, a, b, output);

    if (level > 0) {
        printf("Match found at level %d\n", level);
    } else {
        printf("Match not found\n");
    }

    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);

    return 0;
}
