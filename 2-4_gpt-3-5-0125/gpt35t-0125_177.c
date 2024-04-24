int DoThis(int n, int arr[n], int level){
    int l = n;
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));//sizeof(int)
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        
        // Check if current output is the desired one
        int flag = 1;
        for (k = 0; k < l; k++) {
            if (copy[k] != b[k]) {
                flag = 0;
                break;
            }
        }
        
        if (flag) {
            // Output level when desired output is found
            return level;
        } else {
            // Continue recursing if desired output is not found
            int result = DoThis(n, copy, level + 1);
            if (result != -1) {
                return result;
            }
        }
    }
    
    // Output -1 if desired output is not found at any level
    return -1;
}
