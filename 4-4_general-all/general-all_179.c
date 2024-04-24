int **DoThis(int n, int arr[n]){
    int l = n;
    int **b = malloc(l * sizeof(*b));
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        if (copy == NULL) {
            // Error handling for memory allocation failure
            for (int m = 0; m < i; m++) {
                free(b[m]);
            }
            free(b);
            return NULL;
        }
        memcpy(copy, arr, l * sizeof(*copy));
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}
int FindLevel(int n, int arr[n], int target[], int level) {
    int **output = DoThis(n, arr);
    if (output == NULL) {
        return -1; // Memory allocation failure
    }
    for (int i = 0; i < n; i++) {
        if (memcmp(output[i], target, n * sizeof(int)) == 0) {
            for (int j = 0; j < n; j++) {
                free(output[j]);
            }
            free(output);
            return level;
        }
        int subLevel = FindLevel(n, output[i], target, level + 1);
        if (subLevel != -1) {
            for (int j = 0; j < n; j++) {
                free(output[j]);
            }
            free(output);
            return subLevel;
        }
    }
    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);
    return -1; // Target output not found in this level
}
int a[] = {2, 3, 4, 1};
int b[] = {1, 2, 4, 3};
int level = FindLevel(4, a, b, 1);
if (level != -1) {
    printf("Target found at level: %d\n", level);
} else {
    printf("Target not found\n");
}
