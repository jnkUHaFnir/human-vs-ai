int **DoThis(int n, int arr[n]){
    int l = n;
    int **b = malloc(l * sizeof(*b)); // Allocate memory for array of pointers

    if(b == NULL) {
        // Handle failed memory allocation
        return NULL;
    }

    for (int i = 0; i < l; i++) {
        b[i] = malloc(l * sizeof(int)); // Allocate memory for the integer array

        if(b[i] == NULL) {
            // Handle failed memory allocation
            return NULL;
        }

        for (int k = 0; k < l; k++)
            b[i][k] = arr[k];

        int j = (i + 1) % l;
        int t = b[i][i];
        b[i][i] = b[i][j];
        b[i][j] = t;
    }
    return b;
}

void freeMemory(int n, int **arr){
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
}
