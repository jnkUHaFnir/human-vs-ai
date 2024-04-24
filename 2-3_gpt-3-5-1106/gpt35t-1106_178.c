int **DoThis(int level, int n, int arr[n], int original[n]) {
    int l = n;
    int **b = malloc(l * sizeof(*b));//sizeof(*b) : sizeof(int *)
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));//sizeof(int)
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        //printf("{%d, %d, %d, %d}\n", copy[0], copy[1], copy[2], copy[3]);
        int isEqual = 1;
        for (int m = 0; m < l; m++) {
            if (copy[m] != original[m]) {
                isEqual = 0;
                break;
            }
        }
        if (isEqual) {
            printf("Found at level %d\n", level);
            return b;
        } else {
            b[i] = copy;
        }
    }
    int **result = NULL;
    for (int m = 0; m < l; m++) {
        if (b[m] != NULL) {
            result = DoThis(level + 1, n, b[m], original);
            if (result != NULL) {
                break;
            }
        }
    }
    return result;
}
int main() {
    int a[] = {2, 3, 4, 1};
    int level = 1;
    int **result = DoThis(level, 4, a, a);
    return 0;
}
